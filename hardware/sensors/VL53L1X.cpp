#include "VL53L1X.hpp"

/*
int Init(int address);
        int SetI2CAddress(int newAddress);
        int StartRanging();
        int StopRanging();
        int GetDistance(int *distance);
        */

using namespace VMOS;

int VMOS::VL53L1X::Init(u_int8_t address)
{
        i2cClient.setup(address);
}

int VMOS::VL53L1X::StartRanging()
{
        Logging::Log("VL53L1X", "StartRanging", "Enabling Ranging");
        i2cClient.writeData(VL53L1XRegister::SYSTEM_MODE_START, 0x40); // Enable
}

int VMOS::VL53L1X::StopRanging()
{
        i2cClient.writeData(VL53L1XRegister::SYSTEM_MODE_START, 0x00); // Enable
}

int VMOS::VL53L1X::GetDistance(int *distance)
{
        char data1, data2;

        if (i2cClient.readData(data1, VL53L1XRegister::RESULT_FINAL_CROSS_TALK_CORRECTED_RANGE_MM) != 0)
        {
                Logging::Log("BNO055", "GetFusedOrientation", "Failed to get I2C Data");
                return 1;
        }

        if (i2cClient.readData(data2, VL53L1XRegister::RESULT_FINAL_CROSS_TALK_CORRECTED_RANGE_MM + 1) != 0)
        {
                Logging::Log("BNO055", "GetFusedOrientation", "Failed to get I2C Data");
                return 1;
        }


        *distance = (int)((data1 << 8) + data2);

        return 0;
}