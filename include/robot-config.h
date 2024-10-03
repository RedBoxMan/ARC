#pragma once

#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

extern brain Brain;
extern controller Controller1;

extern motor RFront;
extern motor RBack;

extern motor_group Rdrive;

extern motor LFront;
extern motor LBack;

extern motor_group Ldrive;

extern inertial inertial1;
extern inertial inertial2;