#ifndef HARDWARE_PROCESSOR_ARDUINO_H
#define HARDWARE_PROCESSOR_ARDUINO_H

#include "base_hardware_processor.h"
#include <cstdio>
#include <chrono>
#include <iostream>
#include <thread>

class HardwareProcessorWindows : public BaseHardwareProcessor
{
public:
  HardwareProcessorWindows() : BaseHardwareProcessor()
  {
    this->program_start = std::chrono::steady_clock::now();
  };

  std::chrono::_V2::steady_clock::time_point program_start;

  void setup() override
  {
  }

  unsigned long microsecondsTimestamp() override
  {
    auto now = std::chrono::steady_clock::now();
    auto duration = now - program_start;

    return std::chrono::duration_cast<std::chrono::microseconds>(duration).count();
  }

  unsigned long millisecondsTimestamp() override
  {
    auto now = std::chrono::steady_clock::now();
    auto duration = now - program_start;

    return std::chrono::duration_cast<std::chrono::milliseconds>(duration).count();
  }

  void sleepMilliseconds(int milliseconds) override
  {
    std::this_thread::sleep_for(std::chrono::milliseconds(milliseconds));
  }

  void print(char *array) override
  {
    printf(array);
  }
};

#endif // HARDWARE_PROCESSOR_ARDUINO_H