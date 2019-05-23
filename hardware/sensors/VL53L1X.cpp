#include "VL53L1X.hpp"

/*
int Init(int address);
        int SetI2CAddress(int newAddress);
        int StartRanging();
        int StopRanging();
        int GetDistance(int *distance);
        */

using namespace VMOS;
uint8_t configBlock[] = {
    0x29, 0x02, 0x10, 0x00, 0x28, 0xBC, 0x7A, 0x81, //8
    0x80, 0x07, 0x95, 0x00, 0xED, 0xFF, 0xF7, 0xFD, //16
    0x9E, 0x0E, 0x00, 0x10, 0x01, 0x00, 0x00, 0x00, //24
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x34, 0x00, //32
    0x28, 0x00, 0x0D, 0x0A, 0x00, 0x00, 0x00, 0x00, //40
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x11, //48
    0x02, 0x00, 0x02, 0x08, 0x00, 0x08, 0x10, 0x01, //56
    0x01, 0x00, 0x00, 0x00, 0x00, 0xFF, 0x00, 0x02, //64
    0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x0B, 0x00, //72
    0x00, 0x02, 0x0A, 0x21, 0x00, 0x00, 0x02, 0x00, //80
    0x00, 0x00, 0x00, 0xC8, 0x00, 0x00, 0x38, 0xFF, //88
    0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x91, 0x0F, //96
    0x00, 0xA5, 0x0D, 0x00, 0x80, 0x00, 0x0C, 0x08, //104
    0xB8, 0x00, 0x00, 0x00, 0x00, 0x0E, 0x10, 0x00, //112
    0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x0F, //120
    0x0D, 0x0E, 0x0E, 0x01, 0x00, 0x02, 0xC7, 0xFF, //128
    0x8B, 0x00, 0x00, 0x00, 0x01, 0x01, 0x40        //129 - 135 (0x81 - 0x87)
};
int VMOS::VL53L1X::Init(u_int8_t address)
{
        Logging::Log("VL53L1X", "Init", "Enabling Sensor...");
        i2cClient.setup(address);
        i2cClient.writeData(VL53L1XRegister::SOFT_RESET, 0x00);
        usleep(100000);
        i2cClient.writeData(VL53L1XRegister::SOFT_RESET, 0x01);

        usleep(500000);
        i2cClient.writeData(VL53L1XRegister::DSS_CONFIG__TARGET_TOTAL_RATE_MCPS_LO, 0x00);
        i2cClient.writeData(VL53L1XRegister::DSS_CONFIG__TARGET_TOTAL_RATE_MCPS_HI, 0xA0);
        i2cClient.writeData(VL53L1XRegister::RANGE_CONFIG_VCSEL_PERIOD_A, 0x0F);
        i2cClient.writeData(VL53L1XRegister::RANGE_CONFIG_VCSEL_PERIOD_B, 0x0D);
        i2cClient.writeData(VL53L1XRegister::RANGE_CONFIG_VALID_PHASE_HIGH, 0xB8);
        i2cClient.writeData(VL53L1XRegister::SD_CONFIG__WOI_SD0, 0x0F);
        i2cClient.writeData(VL53L1XRegister::SD_CONFIG__WOI_SD1, 0x0D);
        i2cClient.writeData(VL53L1XRegister::SD_CONFIG__INITIAL_PHASE_SD0, 14);
        i2cClient.writeData(VL53L1XRegister::SD_CONFIG__INITIAL_PHASE_SD1, 14);

        Logging::Log("VL53L1X", "Init", "Sensor Enabled!");
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
        uint8_t offset = 0;
        uint8_t address = 1 + offset; //Start at memory location 0x01, add offset
        uint8_t leftToSend = sizeof(configBlock) - offset;
        while (leftToSend > 0)
        {
                uint16_t toSend = 32 - 2; //Max I2C buffer on Arduino is 32, and we need 2 bytes for address
                if (toSend > leftToSend)
                        toSend = leftToSend;

            
             
                for (uint8_t x = 0; x < toSend; x++)
                {
                        i2cClient.writeData(address, configBlock[address + x - 1 - offset]);
                }

                leftToSend -= toSend;
                address += toSend;
        }
        usleep(10000);
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