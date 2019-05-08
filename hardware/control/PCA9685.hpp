#ifndef _PCA9685_H_
#define _PCA9685_H_
#include "core/logging/logging.hpp"
#include "hardware/i2c/i2c.hpp"
#include <unistd.h>
/*
    PCA9685 - Adafruit 16-Channel 12-bit PWM/Servo Ddriver - IC2 Interface

    Allows for PWM Control over i2c interface.

*/

namespace VMOS
{
    class PCA9685{
        private:
            enum PCA9685_Registers{
                MODE1       = 0x00,
                MODE2       = 0x01,
                SUBADR1     = 0x02,
                SUBADR2     = 0x03,
                SUBADR3     = 0x04,
                ALLCALLADR  = 0x05,
                LED_BASE    = 0x06, // We only stoe the base LED then just shift int
                ALL_LED_ON_L = 0xFA,
                ALL_LED_ON_H = 0xFB,
                ALL_LED_OFF_L = 0xFC,
                ALL_LED_OOF_H = 0xFD,
                PRE_SCALE     = 0xFE,
                TestMode      = 0xFF
            };
            I2C i2cClient;
            

        public:
            void init(int freq);
            void setPWM(int channel, int value);
        

    };
} // VMOS


#endif