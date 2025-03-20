#include "vex.h"

using namespace vex;

brain Brain;
controller Controller = controller(primary);

inertial Inertial = inertial(PORT7);

motor LF = motor(PORT1 , ratio6_1 , false);
motor LM = motor(PORT2 , ratio6_1 , false);
motor LB = motor(PORT3 , ratio6_1 , false);
motor RF = motor(PORT4 , ratio6_1 , true);
motor RM = motor(PORT5 , ratio6_1 , true);
motor RB = motor(PORT6 , ratio6_1 , true);