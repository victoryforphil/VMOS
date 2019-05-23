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
    enum VL53L1XRegister
    {
        SOFT_RESET = 0x00,
        DEVICE_ADDRESS = 0x01,
        DSS_CONFIG__TARGET_TOTAL_RATE_MCPS  = 0x0024,
        DSS_CONFIG__TARGET_TOTAL_RATE_MCPS_HI = 0x0024,
        DSS_CONFIG__TARGET_TOTAL_RATE_MCPS_LO = 0x0025,
        RANGE_CONFIG_VCSEL_PERIOD_A = 0x0060,
        RANGE_CONFIG_VCSEL_PERIOD_B = 0x0063,
        RANGE_CONFIG_VALID_PHASE_LOW = 0x0068,
        RANGE_CONFIG_VALID_PHASE_HIGH = 0x0069,
        SYSTEM_THRESH_HIGH = 0x0072,
        SYSTEM_THRESH_HIGH_HI = 0x0072,
        SYSTEM_THRESH_HIGH_LO = 0x0073,
        SYSTEM_THRESH_LOW = 0x0074,
        SYSTEM_THRESH_LOW_HI = 0x0074,
        SYSTEM_THRESH_LOW_LO = 0x0075,
        SYSTEM_ENABLE_XTALK_PER_QUADRANT = 0x0076,
        SYSTEM_SEED_CONFIG = 0x0077,
        SD_CONFIG__WOI_SD0 = 0x0078,
        SD_CONFIG__WOI_SD1 = 0x0079,
        SD_CONFIG__INITIAL_PHASE_SD0 = 0x007A,
        SD_CONFIG__INITIAL_PHASE_SD1 = 0x007B,
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
