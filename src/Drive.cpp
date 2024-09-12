#include "Drive.h"

Drive::Drive(motor_group left_drive, motor_group right_drive, float wheel_diameter)
{

}

void Drive::arcade()
{

}

void Drive::tank(){}

void Drive::drive_distance(float distance)
{
    PID drive_PID(10, 10, 10);

    float start_left_position = left_drive.position(degrees);
    float start_right_position = right_drive.position(degrees);

    float current_left_position, current_right_position, average_distance;

    while()
    {
        current_left_position = start_left_position - left_drive.position(degrees);
        current_right_position = start_right_position - right_drive.position(degrees);

        average_distance = (current_left_position + current_right_position) / 2;

        float output = drive_PID.compute(distance, average_distance);
    }
}

void Drive::turn_angle(){}

void Drive::turn_to_angle(){}