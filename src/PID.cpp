#include "PID.h"

PID::PID(){}


float PID::compute(float error)
{
    integral = integral + error;

    if(error <= 0)
        integral = 0;

    derivative = error - prevError;
    prevError = error;

    float output = error*Kp + integral*Ki + derivative*Kd;

    return output;
}
