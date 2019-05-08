#include "drive_subsystem.hpp"
#include <unistd.h>

#include <google/protobuf/arena.h>

using namespace VMOS;
using namespace VictoryCar;


 
void DriveSubsystem::operator()()
{   
    Logging::Log("DriveSubsystem", "init", "Creating PWM Controler.");

    pwmControl = new PCA9685();
    pwmControl->init(255);
    queue = VMOS::QueueManager<DriveSubsystemInput>::fetch("drive-thread");
    usleep(50000);
    Logging::Log("DriveSubsystem", "init", "Arming...");

    pwmControl->setPWM(0, 1500);

    usleep(1000 * 1000 * 2);
    Logging::Log("DriveSubsystem", "init", "Armed!");

    while (true)
    {
        tick();
        usleep(1000); // 1ms (1000hz)
      
    }
}



void DriveSubsystem::tick()
{
    
    DriveSubsystemInput output;
    queue->getLatest(output);

    int pwmThrottleValue = (1000 *  output.throttle()) + 1500;
    pwmControl->setPWM(0, pwmThrottleValue);
    
    int pwmSteerValue = (1000 *  output.throttle()) + 1000;
    pwmControl->setPWM(1, pwmSteerValue);
}

