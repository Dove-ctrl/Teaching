#include "vex.h"

using namespace vex;

brain Brain;
controller Controller = controller(primary);

motor Motor = motor(PORT1 , ratio18_1 , false);