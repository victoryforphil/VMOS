#include "sensor_subsystem.hpp"
#include <unistd.h>
using namespace VMOS;
using namespace TestBed;



void VMOS::TestBed::SensorSubsystem::operator()()
{
    imu = new BNO055();
    imu->Init();
   
    while (true)
    {
        tick();
        usleep(10000); // 10ms (100hz)
      
    }
}



void VMOS::TestBed::SensorSubsystem::tick()
{
    //imu->GetFusedOrientation(MessageQueue::getRef());
}

