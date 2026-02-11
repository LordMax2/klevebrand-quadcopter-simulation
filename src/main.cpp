#include "klevebrand_maxfly_drone.h"
#include "virtual_drone_motor.h"
#include "ArduinoFake.h"
#include <cstdio>

using namespace fakeit;

int main()
{
  VirtualDroneMotor motors[4];

  KlevebrandMaxFlyDrone drone = KlevebrandMaxFlyDrone(motors);

  When(Method(ArduinoFake(), micros)).AlwaysReturn();
  When(Method(ArduinoFake(), millis)).AlwaysReturn();
  When(Method(ArduinoFake(), delay)).AlwaysReturn();
  When(OverloadedMethod(ArduinoFake(Serial), println, size_t(const String &s))).AlwaysReturn();

  drone.setup();

  printf("Start\n");

  while (true)
  {
    printf("run\n");

    drone.run();
  }

  return 0;
}
