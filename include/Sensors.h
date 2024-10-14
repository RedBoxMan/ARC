#pragma once

#include "vex.h"

using namespace vex;

class inertial_group
{
    private:

    inertial* list;
    int size = 0;

    public:

    template<typename... Param>
    inertial_group(Param ... param);

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