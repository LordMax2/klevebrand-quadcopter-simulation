#include "klevebrand_maxfly_drone.h"
#include "virtual_drone_motor.h"

VirtualDroneMotor motors[4];

KlevebrandMaxFlyDrone drone = KlevebrandMaxFlyDrone(motors);

int main()
{
  // Startup the gyroscope and motors
  drone.setup();

  while(true) {
    drone.run();
  }

  return 0;
}
