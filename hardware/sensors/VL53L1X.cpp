#include "VL53L1X.hpp"


using namespace VMOS;

int VMOS::VL53L1X::Init(u_int8_t address){
    mAddress = address;
    uint8_t boot;
    Logging::Log("VL53L1X", "Init", "Sensor waiting to boot!");
    
    
    int status = VL53L1X_SensorInit(mAddress);
   
    std::cout << "BOOT STATE: " << std::to_string(boot) << std::endl; 
    if(status != 0){
        Logging::Log("VL53L1X", "Init", "Error Status: " + std::to_string(status));
    }else{
         Logging::Log("VL53L1X", "Init", "Sensor Created!");
    }
    return status;
}

int VMOS::VL53L1X::SetI2CAddress(u_int8_t newAddress){
     return 0;
}

int VMOS::VL53L1X::StartRanging(){
    VL53L1X_StartRanging(mAddress);
     return 0;
}

int VMOS::VL53L1X::StopRanging(){
     return 0;
}

int VMOS::VL53L1X::GetDistance(u_int16_t *distance){
    VL53L1X_GetDistance(mAddress, distance);
    return 0;
}