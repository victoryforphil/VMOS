#include "VL53L1X_Lite.hpp"

using namespace VMOS;


int VMOS::VL53L1XLite::Init(u_int8_t address)
{

     usleep(5000);

     return 0;
}

int VMOS::VL53L1XLite::SetI2CAddress(u_int8_t newAddress)
{
     return 0;
}

int VMOS::VL53L1XLite::StartRanging()
{
     VMOS::Logging::Log("VL53L1X_Lite", "Start Ranging", "starting to range");
    
     return 0;
}

int VMOS::VL53L1XLite::StopRanging()
{
     return 0;
}

int VMOS::VL53L1XLite::GetDistance(int32_t *distance)
{
    
     return 0;
}