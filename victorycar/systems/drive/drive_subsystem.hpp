#ifndef _DRIVE_SUBSYSTEM_H_
#define _DRIVE_SUBSYSTEM_H_
#include <thread>
#include "victorycar/systems/drive/drive.pb.h"
#include "core/threading/message_queue.hpp"
#include "core/threading/queue_manager.hpp"
#include "hardware/control/PCA9685.hpp"
namespace VMOS
{
    namespace VictoryCar
    {
        class DriveSubsystem{
            private:
                
              
                MessageQueue<DriveSubsystemInput>* queue;
                PCA9685* pwmControl;
            public:
                void operator()();
                //void init_tick();
                void tick();

                ~DriveSubsystem(){
                    pwmControl->setPWM(0, 0);
                    pwmControl->setPWM(1, 0);
                }
               

        };
    } // TestBed
    
} // VMOS


#endif