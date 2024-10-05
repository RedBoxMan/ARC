#include "vex.h"

brain Brain;

motor RFront = motor(PORT11, ratio36_1, false);
motor RBack = motor(PORT1, ratio36_1, false);

motor LFront = motor(PORT20, ratio36_1, true);
motor LBack = motor(PORT10, ratio36_1, true);

inertial inertial1 = inertial(PORT16);
inertial inertial2 = inertial(PORT17);

encoder forwardRight = encoder(Brain.ThreeWirePort.A);
encoder forwardLeft = encoder(Brain.ThreeWirePort.C);
encoder lateral = encoder(Brain.ThreeWirePort.E);

