#include "klevebrand_maxfly_drone.h"
#include "virtual_drone_motor.h"
#include "Arduino.h"
#include <cstdio>

int main()
{
  VirtualDroneMotor motors[4];

  KlevebrandMaxFlyDrone drone = KlevebrandMaxFlyDrone(motors);

  printf("Start\n");

  while (true)
  {
    printf("run\n");

    drone.run();
  }

  return 0;
}
