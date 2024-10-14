#include "Sensors.h"

    template<typename... Param>
    inertial_group::inertial_group(Param ... param) : size(sizeof...(param))
    {
        inertial test[] = {inertial(param...)};
        list = test;
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

    void inertial_group::setHeading(float heading)
    {

    }

    float inertial_group::getHeading()
    {
        return 0;
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