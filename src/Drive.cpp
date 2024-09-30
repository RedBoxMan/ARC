#include "Drive.h"

Drive::Drive(motor_group left_drive, motor_group right_drive, float wheel_diameter, float max_voltage)
{

}

void Drive::arcade()
{

}

void Drive::tank(){}

float Drive::deg_to_inches(float deg)
{
    return deg * pi() / 180 * wheel_diameter;
}

float Drive::brake()
{
    brake(true, true);
}

float Drive::brake(bool left, bool right)
{
    if(left)
        left_drive.stop();
    if(right)
        right_drive.stop();
}

void Drive::drive_distance(float distance)
{
    PID drive_PID(10.0, 10.0, 10.0);

    float start_left_position = deg_to_inches(left_drive.position(degrees));
    float start_right_position = deg_to_inches(right_drive.position(degrees));

    float current_left_position, current_right_position, average_distance;

    //  While loop should end when PID is complete
    while(distance - average_distance > 0)
    {
        current_left_position = start_left_position - deg_to_inches(left_drive.position(degrees));
        current_right_position = start_right_position - deg_to_inches(right_drive.position(degrees));

        average_distance = (current_left_position + current_right_position) / 2;

        float output = drive_PID.compute(distance, average_distance);
    }

    brake();
}

void Drive::turn_angle(){}

void Drive::turn_to_angle(){}