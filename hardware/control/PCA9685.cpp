#include "PCA9685.hpp"

using namespace VMOS;

void PCA9685::init(int freq){

    i2cClient.setup(0x40);

    int prescale = (25000000 / 4096) / freq;
    prescale -= 1.0;

    i2cClient.writeData(0x00, 0x10);
    usleep(5000);
    i2cClient.writeData(0xFE, prescale);
    usleep(5000);
    i2cClient.writeData(0x00, 0x01);
    usleep(5000);
    i2cClient.writeData(0x00, 0x08);


}

void PCA9685::setPWM(int chan, int value){
    int low = value & 0xFF;
    int high = value >> 8;

    i2cClient.writeData(0x08 + (chan * 4), low);
    i2cClient.writeData(0x09 + (chan * 4), high);
}