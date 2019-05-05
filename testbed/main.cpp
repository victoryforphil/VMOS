#include <iostream>
#include "core/threading/threading.h"
#include "core/math/euler.hpp"
#include "core/math/conversions.hpp"
#include "hardware/sensors/BNO055.h"
#include "core/logging/logging.hpp"
#include "hardware/i2c/i2c.hpp"
#include <string>
using namespace VMOS;

int main(){
    Threading t;
    t.Run();
    
    VMOS::Logging::Log("TestBed", "main" , "VMOS Test Bed Running.");

    Euler imu_test = BNO055().GetFusedOrieentation();

    VMOS::Logging::Log("TestBed", "main", imu_test.ToString());

    BNO055 imu;
    imu.Init();


    VMOS::Logging::Log("TestBed", "main - IMU", "Beginning BNO055 IMU Test over i2c");
    VMOS::Logging::Log("TestBed", "main - IMU", "IMU ID: " 
        + std::to_string( imu.GetChipID()));
    VMOS::Logging::Log("TestBed", "main - IMU", "IMU Temp: " 
        + std::to_string( imu.GetTempature()) + "c");
    VMOS::Logging::Log("TestBed", "main - IMU", "IMU Temp: " 
        + std::to_string(VMOS::Conversions::celiusToFahrenhiet( imu.GetTempature())) + "f");

    return 0;
}