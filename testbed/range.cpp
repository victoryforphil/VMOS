#include <iostream>
#include "core/logging/logging.hpp"
#include <string>
#include <thread>
#include "hardware/sensors/VL53L1X.hpp"
using namespace VMOS;

int main(){
    
    VMOS::Logging::Log("TestBed", "main" , "VMOS Test Bed Running.");

    VL53L1X lidar;
    lidar.Init(0x29);
    lidar.StartRanging();
    while(true){
        int distance = -1;
        
        lidar.GetDistance(&distance);
        std::cout<<"Lidar: " << distance << std::endl;
    }

    return 0;
}