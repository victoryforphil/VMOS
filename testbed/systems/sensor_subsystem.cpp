#include "sensor_subsystem.hpp"

using namespace VMOS;
using namespace TestBed;

void VMOS::TestBed::SensorSubsystem::start(){
  
    imu->Init();
    while(true){
        tick();
        sleep(10);
    }
}

void VMOS::TestBed::SensorSubsystem::tick(){
    imu->GetFusedOrientation(angel);
}

Euler VMOS::TestBed::SensorSubsystem::GetAngle(){
    return *angel;
}