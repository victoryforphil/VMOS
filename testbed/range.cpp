#include <iostream>
#include "core/logging/logging.hpp"
#include <string>
#include <thread>
#include "hardware/sensors/VL53L1X_Lite.hpp"
using namespace VMOS;

int main(){
    
    VMOS::Logging::Log("TestBed", "main" , "VMOS Test Bed Running.");

    VL53L1XLite lidar;

    lidar.Init(0x30);
    usleep(10000);
    
    lidar.StartRanging(1);

    while(1){
      int32_t rangeMm;
      lidar.GetDistance(&rangeMm);
      printf("Range: %d mm, %d in \n",rangeMm, (int)(rangeMm / 25.4));
    }



    return 0;
}