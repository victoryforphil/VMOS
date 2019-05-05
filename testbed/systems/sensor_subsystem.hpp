#ifndef _SENSOR_SUBSYSTEM_H_
#define _SENSOR_SUBSYSTEM_H_
#include "hardware/sensors/BNO055.h"
#include <thread>
namespace VMOS
{
    namespace TestBed
    {
        class SensorSubsystem{
            private:
                static BNO055* imu;
                static std::thread* run_thread;
                
                //TODO: Replace with Message Queue
                static Euler* angel;


                static void init_tick();
            public:
                static void start();
                static void tick();
                static Euler GetAngle();

        };
    } // TestBed
    
} // VMOS


#endif