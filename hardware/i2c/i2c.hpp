/*
Defines all fuctions to use i2c-based devices
*/

#ifndef _I2C_H_
#define _I2C_H_

#include <unistd.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <linux/i2c-dev.h>
#include <string>

namespace VMOS
{
    class I2C{
        private:
            char* path = (char*)"/dev/i2c-1";
            int file;
        public:
            //I2C();
            int setup(int addr);
            int readData(char &out, char reg);
            int writeData(char reg, char data);
    };
} // VMOS


#endif