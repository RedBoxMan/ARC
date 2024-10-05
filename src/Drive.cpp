#include "Drive.h"

Drive::Drive(motor_group left_drive, motor_group right_drive, float wheel_diameter, float max_voltage) : 
left_drive(left_drive), 
right_drive(right_drive), 
wheel_diameter(wheel_diameter), 
max_voltage(max_voltage)
{}

void Drive::arcade()
{

}

void Drive::tank(){}

float Drive::deg_to_inches(float deg)
{
    return (deg / 360) * pi() * wheel_diameter;
}

void Drive::brake()
{
    brake(true, true);
}

//Brakes 
void Drive::brake(bool left, bool right)
{
    if(left)
        left_drive.stop();
    if(right)
        right_drive.stop();
}

//Drives given distance in inches using a PID loop
void Drive::drive_distance(float distance)
{
    PID drive_PID(1.0, 1.0, 1.0);
    
    float start_left_position = deg_to_inches(left_drive.position(degrees));
    float start_right_position = deg_to_inches(right_drive.position(degrees));

    float current_left_position = deg_to_inches(left_drive.position(degrees));
    float current_right_position = deg_to_inches(right_drive.position(degrees));

    float average_distance = (current_left_position + current_right_position) / 2;

    distance = distance + average_distance;

    //  While loop should end when PID is complete
    while(!drive_PID.isSettled())
    {
        current_left_position =  deg_to_inches(left_drive.position(degrees)) - start_left_position;
        current_right_position = deg_to_inches(right_drive.position(degrees)) - start_right_position;

        average_distance = (current_left_position + current_right_position) / 2;
        float error = distance - average_distance;

        Brain.Screen.clearScreen();

        float output = drive_PID.compute(error);
        output = clamp(output, -max_voltage, max_voltage);

        left_drive.spin(forward, output, volt);
        right_drive.spin(forward, output, volt);

        Brain.Screen.setCursor(1,1);
        Brain.Screen.print(error);
        Brain.Screen.setCursor(2,1);
        Brain.Screen.print(output);

        wait(10, msec);

    }

    brake();
}

void Drive::turn_angle(){}

void Drive::turn_to_angle(){}