#pragma once

#include "vex.h"

using namespace vex;

class Drive
{
    motor_group left_drive, right_drive;
    //gyro Gyro;
    float wheel_diameter;

    Drive(motor_group left_drive, motor_group right_drive, float wheel_diameter);

    void arcade();
    void tank();

    void drive_distance();

    void turn_angle();
    void turn_to_angle();
};