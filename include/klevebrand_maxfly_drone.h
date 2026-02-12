#ifndef KLEVEBRAND_MAXFLY_DRONE_H
#define KLEVEBRAND_MAXFLY_DRONE_H

#include "template_gyro_drone.h"
#include "quadcopter_pid.h"
#include "virtual_drone_gyro.h"
#include "virtual_drone_motor.h"
#include "virtual_drone_pid_repository.h"
#include <cstdio>

class KlevebrandMaxFlyDrone : public TemplateGyroDrone<QuadcopterPid, VirtualDroneGyro, VirtualDronePidRepository>
{
private:
  VirtualDroneMotor *_motors;
  VirtualDroneMotor& motorLeftFront() { return _motors[0]; };
  VirtualDroneMotor& motorRightFront() { return _motors[1]; };
  VirtualDroneMotor& motorLeftBack() { return _motors[2]; };
  VirtualDroneMotor& motorRightBack() { return _motors[3]; };
  VirtualDroneGyro _gyro;
  VirtualDronePidRepository _pid_repository;
  void printThrottle();

public:
  KlevebrandMaxFlyDrone(VirtualDroneMotor *motors) : TemplateGyroDrone<QuadcopterPid, VirtualDroneGyro, VirtualDronePidRepository>(500, 200, 10000, &_gyro, &_pid_repository)
  {
    this->_motors = motors;
  }

  void setup() override;
  void run() override;
  void runMotors(float gyro_roll, float gyro_pitch, float gyro_yaw) override;
  void setupMotors() override
  {
    motorLeftFront().setSpeed(0);
    motorRightFront().setSpeed(0);
    motorLeftBack().setSpeed(0);
    motorRightBack().setSpeed(0);

    delay(1000);
  };
  void stopMotors() override
  {
    motorLeftFront().setSpeed(0);
    motorRightFront().setSpeed(0);
    motorLeftBack().setSpeed(0);
    motorRightBack().setSpeed(0);
  };
};

#endif
