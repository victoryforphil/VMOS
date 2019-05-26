#ifndef _VL53L1X_H
#define _VL53L1X_H
#include <linux/i2c.h>

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <unistd.h>    //Needed for I2C port
#include <fcntl.h>     //Needed for I2C port
#include <sys/ioctl.h> //Needed for I2C port
#include <linux/i2c-dev.h>
#include "hardware/i2c/i2c.hpp"
#include "core/logging/logging.hpp"
#include "hardware/sensors/VL53L1X_STLIB/VL53L1X_api.h"
// LIDAR DISTANCE SENSOR

namespace VMOS
{
class VL53L1X
{
private:
    u_int8_t mAddress;

public:
    

    int Init(u_int8_t address);
    int SetI2CAddress(u_int8_t newAddress);
    int StartRanging();
    int StopRanging();
    int GetDistance(uint16_t *distance);
};

} // namespace VMOS

#endif
