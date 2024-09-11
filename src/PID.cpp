#include "PID.h"

PID::PID(float Kp, float Ki, float Kd)
{
    this->Kp = Kp;
    this->Ki = Ki;
    this->Kd = Kd;
}

float PID::compute(float setpoint, float input)
{
    error = setpoint - error;

    integral = integral + error;

    if(error <= 0)
        integral = 0;

    derivative = error - prevError;
    prevError = error;

    output = error*Kp + integral*Ki + derivative*Kd;

    return output;
}