#pragma once

#include "vex.h"

//PID Class
class PID
{

    private:
    
    float Kp, Ki, Kd;

    float prevError;
    float integral, derivative;
    float output;
    float timeSpentSettled = 0;

    public:

    PID(float Kp, float Ki, float Kd);

    float compute(float error);

    bool isSettled();
};