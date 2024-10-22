#include "Sensors.h"

    inertial_group::inertial_group(inertial * sensorArray, int arraySize)
    {
        sensors = sensorArray;
        size = arraySize;
    }

    void inertial_group::calibrate()
    {
        
    }

    bool inertial_group::isCalibrating()
    {
        return true;
    }

    void inertial_group::resetHeading()
    {

    }

    /// @brief Sets the inertial sensors to a new heading
    /// @param heading The new heading for the sensors
    /// @param unit The rotation unit for the angle
    void inertial_group::setHeading(float heading, rotationUnits unit)
    {
        for(int i = 0; i < size; i++)
            sensors[i].setHeading(heading, unit);
    }

    //Returns the average heading of the inertial sensors and returns a degree in integers
    //Find a way to work with more than two sensors
    float inertial_group::getHeading()
    {
        //Sets the heading to an int since % only works with int
        int m1 = sensors[0].heading();
        int m2 = sensors[1].heading();

        int d1 = (m2 - m1) % 360;
        int d2 = (m1 = m2) % 360;

        if(d1 < d2)
            return m1 + (d1/2);
        else
            return m2 + (d2/2);
    }   

    void inertial_group::resetRotation()
    {

    }

    void inertial_group::setRotation(float rotation)
    {

    }

    float inertial_group::getRotation()
    {
        return 0;
    }

    float inertial_group::acceleration(axisType axis)
    {
        return 0;
    }