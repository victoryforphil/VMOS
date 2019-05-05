#include <iostream>
#include "core/threading/threading.h"
#include "core/math/euler.hpp"
#include "core/math/conversions.hpp"
#include "hardware/sensors/BNO055.h"
#include "core/logging/logging.hpp"
#include "hardware/i2c/i2c.hpp"
#include "testbed/systems/sensor_subsystem.hpp"
#include <string>
using namespace VMOS;

int main(){
    
    VMOS::Logging::Log("TestBed", "main" , "VMOS Test Bed Running.");

    VMOS::TestBed::SensorSubsystem::start();

    for(;;){
        
        VMOS::Logging::Log("TestBed", "main - IMU", "IMU Orient: " + VMOS::TestBed::SensorSubsystem::GetAngle().ToString());

    }

    return 0;
}