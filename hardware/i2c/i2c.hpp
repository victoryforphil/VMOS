/*
Defines all fuctions to use i2c-based devices
*/

#ifndef _I2C_H_
#define _I2C_H_


namespace VMOS
{
    class I2C{
        public:
            char readData();
            char writeData();
    };
} // VMOS


#endif