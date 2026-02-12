#ifndef VIRTUAL_DRONE_PID_REPOSITORY
#define VIRTUAL_DRONE_PID_REPOSITORY

#include "template_pid_repository.h"

class VirtualDronePidRepositoryDriver {

};

class VirtualDronePidRepository : public TemplatePidRepository<VirtualDronePidRepositoryDriver>
{
private:
    VirtualDronePidRepositoryDriver _driver;
public:
    VirtualDronePidRepository() : TemplatePidRepository(&_driver) {}
    
};

#endif // VIRTUAL_DRONE_PID_REPOSITORY