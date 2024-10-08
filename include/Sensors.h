#pragma once

#include "vex.h"

using namespace vex;

class inertial_group
{
    private:

    LinkedList<vex::inertial> inertialList;

    public:

    template<typename P1, typename P2, typename ... Param>
    inertial_group(P1 &p1, P2 &p2, Param& ... param);

    float average();

    void calibrate();
    bool isCalibrating();

    void resetHeading();
    void setHeading(float heading);
    float getHeading();

    void resetRotation();
    void setRotation(float rotation);
    float getRotation();

    float acceleration(axisType axis);

};