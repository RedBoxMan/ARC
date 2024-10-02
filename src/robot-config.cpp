#include "robot-config.h"

motor RFront = motor(PORT11, true);
motor RBack = motor(PORT1, true);

motor_group Rdrive = motor_group(RFront, RBack);

motor LFront = motor(PORT20, true);
motor LBack = motor(PORT10, true);

motor_group Ldrive = motor_group(LFront, LBack);

inertial inertial1 = inertial(PORT16);
inertial inertial2 = inertial(PORT17);

