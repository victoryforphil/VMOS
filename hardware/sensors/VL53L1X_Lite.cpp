#include "VL53L1X_Lite.hpp"

using namespace VMOS;


int VMOS::VL53L1XLite::Init(u_int8_t address)
{

     mAddress = address;
     
     uint8_t bootState = 0;

     while(!bootState){
          VL53L1X_BootState(mAddress, &bootState);
     }

     return VL53L1X_SensorInit(mAddress);
}

int VMOS::VL53L1XLite::SetI2CAddress(u_int8_t newAddress)
{
     VL53L1X_SetI2CAddress(mAddress,newAddress);
     mAddress = newAddress;
     return 0;
}

int VMOS::VL53L1XLite::StartRanging(uint16_t mode)
{
     VMOS::Logging::Log("VL53L1X_Lite", "Start Ranging", "Starting to range");
     VL53L1X_SetDistanceMode(mAddress,mode);
     return VL53L1X_StartRanging(mAddress);
}

int VMOS::VL53L1XLite::StopRanging()
{
     VMOS::Logging::Log("VL53L1X_Lite", "Start Ranging", "Stopping to range");
     return VL53L1X_StopRanging(mAddress);;
}

int VMOS::VL53L1XLite::GetDistance(int32_t *distance)
{
     uint16_t value;

     
     VL53L1X_GetDistance(mAddress, &value);
     VL53L1X_ClearInterrupt(mAddress);
     *distance = value;

     return 0;
}