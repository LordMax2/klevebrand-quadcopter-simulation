#include "klevebrand_maxfly_drone.h"
#include "virtual_drone_motor.h"
#include "ArduinoFake.h"

#include "vehicles/multirotor/api/MultirotorRpcLibClient.hpp"
#include "common/CommonStructs.hpp"

int main()
{
  VirtualDroneMotor motors[4];

  KlevebrandMaxFlyDrone drone = KlevebrandMaxFlyDrone(motors);

  drone.setup();

  printf("Start\n");

  drone.setThrottle(30);

  while (true)
  {
    drone.run();
  }

  return 0;
}
