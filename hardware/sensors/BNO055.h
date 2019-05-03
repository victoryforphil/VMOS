#include <linux/i2c.h>
#include <iostream>
#include <unistd.h>				//Needed for I2C port
#include <fcntl.h>				//Needed for I2C port
#include <sys/ioctl.h>			//Needed for I2C port
#include <linux/i2c-dev.h>	


#include "core/math/euler.hpp"
//https://cdn-shop.adafruit.com/datasheets/BST_BNO055_DS000_12.pdf
class BNO055{
    
    public:
        enum BNO055Register{
            CHIP_IP = 0x00, //DEFAULT: 0xA0, DESC:
            ACC_ID  = 0x01, //DEFAULT: 0xFB, DESC:
            MAG_ID  = 0x02,
            GYR_ID  = 0x03,

            SW_REV_ID_LSB   = 0x04,
            SW_REV_ID_MSB   = 0x05,
            BL_REV_ID       = 0x06,
            PAGE_ID         = 0x07,

            // Accel Data
            ACC_DATA_X_LSB  = 0x08,
            ACC_DATA_X_MSB  = 0x09,
            ACC_DATA_Y_LSB  = 0x0A,
            ACC_DATA_Y_MSB  = 0x0B,
            ACC_DATA_Z_LSB  = 0x0C,
            ACC_DATA_Z_MSB  = 0x0D,

            // Mag data
            MAG_DATA_X_LSB  = 0x0E,
            MAG_DATA_X_MSB  = 0x0F,
            MAG_DATA_Y_LSB  = 0x10,
            MAG_DATA_Y_MSB  = 0x11,
            MAG_DATA_Z_LSB  = 0x12,
            MAG_DATA_Z_MSB  = 0x13,

            // Gyro Data
            GYR_DATA_X_LSB  = 0x14,
            GYR_DATA_X_MSB  = 0x15,
            GYR_DATA_Y_LSB  = 0x16,
            GYR_DATA_Y_MSB  = 0x17,
            GYR_DATA_Z_LSB  = 0x18,
            GYR_DATA_Z_MSB  = 0x19,
            
            // Euler Measurments
            EUL_Heading_LSB = 0x1A,
            EUL_Heading_MSB = 0x1B,
            EUL_Roll_LSB    = 0x1C,
            EUL_Roll_MSB    = 0x1D,
            EUL_Pitch_LSB   = 0x1E,
            EUL_Pitch_MSB   = 0x1F,

            QUA_Data_w_LSB  = 0x20,
            QUA_Data_w_MSB  = 0x21,
            QUA_Data_x_LSB  = 0x22,
            QUA_Data_x_MSB  = 0x23,
            QUA_Data_y_LSB  = 0x24,
            QUA_Data_y_MSB  = 0x25,
            QUA_DATA_z_LSB  = 0x26,
            QUA_Data_z_MSB  = 0x27,

            LIA_Data_X_LSB  = 0x28,
            LIA_Data_X_MSB  = 0x29,
            LIA_Data_Y_LSB  = 0x2A,
            LIA_Data_Y_MSB  = 0x2B,
            LIA_Data_Z_LSB  = 0x2C,
            LIA_Data_Z_MSB  = 0x2D,

            GRV_Data_X_LSB  = 0x2E,
            GRV_Data_X_MSB  = 0x2F,
            GRV_Data_Y_LSB  = 0x30,
            GRV_Data_Y_MSB  = 0x31,
            GRV_Data_Z_LSB  = 0x32,
            GRV_Data_Z_MSB  = 0x33,

            TEMP            = 0x34,
            CALIB_STATE     = 0x35

        };

        enum BNO055Unit{
            
        };

        enum BNO055Mode{

        };
        

        
        bool Init(int i2cPort);
        int Check(); // Check status of IMU (0 = Connected, 1 = Not Connected)
        int GetChipID();
        Euler GetFusedOrieentation();

    private:
        BNO055Mode mSelectedMode;

        int file_i2c;


        unsigned char readI2C(size_t length);

        void mergeLSBMSB(char* in, char** out);

};