#include "klevebrand_maxfly_drone.h"
#include "virtual_drone_motor.h"
#include "ArduinoFake.h"

int main()
{
  VirtualDroneMotor motors[4];

  KlevebrandMaxFlyDrone drone = KlevebrandMaxFlyDrone(motors);

  drone.setup();

  printf("Start\n");

  while (true)
  {
    drone.run();
  }

  return 0;
}
