#pragma once

#include "vex.h"

using namespace vex;

class Drive
{
    motor_group left_drive, right_drive;
    //gyro Gyro;
    float wheel_diameter;

    float max_voltage;

    Drive(motor_group left_drive, motor_group right_drive, float wheel_diameter, float max_voltage);

    void arcade();
    void tank();

    void drive_distance(float distance);

    void turn_angle();
    void turn_to_angle();
};