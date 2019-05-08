#ifndef _SENSOR_SUBSYSTEM_H_
#define _SENSOR_SUBSYSTEM_H_
#include "hardware/sensors/BNO055.h"
#include <thread>
#include "core/threading/message_queue.hpp"
namespace VMOS
{
    namespace TestBed
    {
        class SensorSubsystem{
            private:
                BNO055* imu;
                std::thread* run_thread;
                
                //TODO: Replace with Message Queue

            public:
                void operator()();
                //void init_tick();
                void tick();
              
               

        };
    } // TestBed
    
} // VMOS


#endif