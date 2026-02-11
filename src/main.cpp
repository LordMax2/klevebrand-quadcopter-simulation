#include "klevebrand_maxfly_drone.h"
#include "virtual_drone_motor.h"

VirtualDroneMotor motors[4];

KlevebrandMaxFlyDrone drone = KlevebrandMaxFlyDrone(motors);

void setup()
{
  // Startup the gyroscope and motors
  drone.setup();
}

void loop()
{
  // Run the drone feedback-loop
  drone.run();
}
