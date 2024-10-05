#include "PID.h"

PID::PID(float Kp, float Ki, float Kd):Kp(Kp), Ki(Ki), Kd(Kd)
{
}

float PID::compute(float error)
{
    integral = integral + error;

    if(error <= 0)
        integral = 0;

    derivative = error - prevError;
    prevError = error;

    float output = error*Kp + integral*Ki + derivative*Kd;

    if(output < 0.7 && output > -0.7)
        timeSpentSettled++;

    Brain.Screen.setCursor(5,1);
    Brain.Screen.print(timeSpentSettled);
    
    return output;
}

bool PID::isSettled(){
    if(timeSpentSettled > 100)
        return true;
    else
        return false;
}

