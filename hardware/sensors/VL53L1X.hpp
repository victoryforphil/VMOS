#ifndef _VL53L1X_H
#define _VL53L1X_H
#include <linux/i2c.h>
#include <iostream>
#include <unistd.h>    //Needed for I2C port
#include <fcntl.h>     //Needed for I2C port
#include <sys/ioctl.h> //Needed for I2C port
#include <linux/i2c-dev.h>
#include "hardware/i2c/i2c.hpp"
#include "core/logging/logging.hpp"
// LIDAR DISTANCE SENSOR


namespace VMOS
{
    class VL53L1X
    {
    private:
       I2C i2cClient;
    public:
        enum VL53L1XRegister{
            SOFT_RESET = 0x00,
            DEVICE_ADDRESS = 0x01,
            SYSTEM_MODE_START = 0x0087,
            RESULT_FINAL_CROSS_TALK_CORRECTED_RANGE_MM = 0x0098
        };

        int Init(u_int8_t address);
        int SetI2CAddress(u_int8_t newAddress);
        int StartRanging();
        int StopRanging();
        int GetDistance(int *distance);
    };

       
} // namespace VMOS


#endif
