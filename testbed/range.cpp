#include <iostream>
#include "core/logging/logging.hpp"
#include <string>
#include <thread>
#include "hardware/sensors/VL53L1X.hpp"
using namespace VMOS;

int main(){
    
    VMOS::Logging::Log("TestBed", "main" , "VMOS Test Bed Running.");

    VL53L1X lidar;
    int status = 0;
    status = lidar.Init(0x29);

    if(status != 0){ VMOS::Logging::Log("TestBed", "main" , "Error Init");}
    status = lidar.StartRanging();
    if(status != 0){ VMOS::Logging::Log("TestBed", "main" , "Error Start Range");}
    while(true){
        int32_t distance = -2;
        
        status = lidar.GetDistance(&distance);
        if(status != 0){ VMOS::Logging::Log("TestBed", "main" , "Error Get Distance" + std::to_string(status));}
        std::cout<<"Lidar: " << distance << std::endl;
          usleep(10);
    }

    return 0;
}