#include "vex.h"

brain Brain;

motor RFront = motor(PORT11, false);
motor RBack = motor(PORT1, false);

motor LFront = motor(PORT20, true);
motor LBack = motor(PORT10, true);

inertial inertial1 = inertial(PORT16);
inertial inertial2 = inertial(PORT17);

