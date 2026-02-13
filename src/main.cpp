#include "klevebrand_maxfly_drone.h"
#include "virtual_drone_motor.h"
#include "ArduinoFake.h"
#include <cstdio>
#include <chrono>
#include <iostream>
#include <thread>

using namespace fakeit;

static const auto program_start = std::chrono::steady_clock::now();

unsigned long nativeMillis()
{
  auto now = std::chrono::steady_clock::now();
  auto duration = now - program_start;
  return std::chrono::duration_cast<std::chrono::milliseconds>(duration).count();
}

unsigned long nativeMicros()
{
  auto now = std::chrono::steady_clock::now();
  auto duration = now - program_start;
  return std::chrono::duration_cast<std::chrono::microseconds>(duration).count();
}

int main()
{
  VirtualDroneMotor motors[4];

  KlevebrandMaxFlyDrone drone = KlevebrandMaxFlyDrone(motors);

  When(Method(ArduinoFake(), micros)).AlwaysReturn(nativeMicros());
  When(Method(ArduinoFake(), millis)).AlwaysReturn(nativeMillis());
  When(Method(ArduinoFake(), delay)).AlwaysReturn();

  When(OverloadedMethod(ArduinoFake(Serial), println, size_t(const char *)))
      .AlwaysReturn();

  When(OverloadedMethod(ArduinoFake(Serial), println, size_t(const String &)))
      .AlwaysReturn();

  When(OverloadedMethod(ArduinoFake(Serial), print, size_t(const char *)))
      .AlwaysReturn();

  drone.setup();

  printf("Time now: %d\n", nativeMillis());
  printf("Start\n");

  while (true)
  {
    drone.run();
  }

  return 0;
}
