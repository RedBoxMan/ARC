#pragma once

#include "vex.h"

//PID Class
class PID
{
    float Kp, Ki, Kd;

    float error, prevError;
    float integral, derivative;
    float output;

    PID(float Kp, float Ki, float Kd);

    float compute(float setpoint, float input);
};