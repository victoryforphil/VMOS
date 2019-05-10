#include <iostream>
#include "victorycar/systems/drive/drive_subsystem.hpp"
int main()
{
    VMOS::Logging::Log("TestBed", "main", "VMOS Victory Car Main Application Running.");

    VMOS::VictoryCar::DriveSubsystem driveSub;
    std::thread driveTrhead(std::ref(driveSub));
    driveTrhead.detach();

    MessageQueue<VMOS::VictoryCar::DriveSubsystemInput> *queue = VMOS::QueueManager<VMOS::VictoryCar::DriveSubsystemInput>::fetch("drive-thread");

    float cur_throttle = 0;
    bool flip = false;
     usleep(1000 * 1000 * 2); // 500  ms
    for (;;)
    {

        VMOS::VictoryCar::DriveSubsystemInput message;
        message.set_steer((cur_throttle / 2) - 1.0);
        message.set_throttle(cur_throttle);
        
        queue->write(message);
  
        usleep(1000 * 500); // 500  ms

        if(cur_throttle < 1.0 ){
            if(flip == false){
                cur_throttle += 0.1;
            }
        }else {
            flip = true;
        }

        if(cur_throttle > 0 ){
            if(flip){
                cur_throttle -= 0.1;
            }
        }else{
            flip = false;
        }

        std::cout << "Throttle" << (float)cur_throttle << std::endl;

    }

    return 0;
}