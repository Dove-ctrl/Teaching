#include "vex.h"

using namespace vex;

brain Brain;
controller Controller = controller(primary);

motor LF = motor(PORT1 , ratio6_1 , false);
motor LF = motor(PORT2 , ratio6_1 , false);
motor LF = motor(PORT3 , ratio6_1 , false);
motor LF = motor(PORT4 , ratio6_1 , true);
motor LF = motor(PORT5 , ratio6_1 , true);
motor LF = motor(PORT6 , ratio6_1 , true);