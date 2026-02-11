#ifndef VIRTUAL_DRONE_GYRO_H
#define VIRTUAL_DRONE_GYRO_H

#include "template_drone_gyro.h"

class VirtualDroneGyroDriver {

};

class VirtualDroneGyro : public TemplateDroneGyro<VirtualDroneGyroDriver> {
private:
    VirtualDroneGyroDriver _driver;

public:
    VirtualDroneGyro() : TemplateDroneGyro(_driver) {};

};

#endif // VIRTUAL_DRONE_GYRO_H