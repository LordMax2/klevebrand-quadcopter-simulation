#ifndef VIRTUAL_DRONE_MOTOR_H
#define VIRTUAL_DRONE_MOTOR_H

#include "base_drone_motor.h"

class VirtualDroneMotor : public BaseDroneMotor
{
public:
    VirtualDroneMotor() : BaseDroneMotor() {};

    void setSpeed(float percentage) override {

    }
};

#endif // VIRTUAL_DRONE_MOTOR