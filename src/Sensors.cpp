#include "Sensors.h"

    template<typename P1, typename P2, typename ... Param>
    inertial_group::inertial_group(P1 &p1, P2 &p2, Param& ... param)
    {
        inertialList.appendNode(P1);
        inertialList.appendNode(P2);

        const auto remainder = inertialList.appendNode(param...);
    }

    float inertial_group::average()
    {
        
    }

    void inertial_group::calibrate()
    {

    }
    bool inertial_group::isCalibrating()
    {

    }

    void inertial_group::resetHeading()
    {

    }
    void inertial_group::setHeading(float heading)
    {

    }
    float inertial_group::getHeading()
    {

    }

    void inertial_group::resetRotation()
    {

    }
    void inertial_group::setRotation(float rotation)
    {

    }
    float inertial_group::getRotation()
    {

    }

    float inertial_group::acceleration(axisType axis)
    {

    }