#pragma once

#include "vex.h"

//PID Class
class PID
{
    float Kp, Ki, Kd;

    float integral, derivative;

    float prevError;

    PID();

    float compute(float error);

};