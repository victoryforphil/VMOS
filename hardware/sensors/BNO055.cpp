#include "BNO055.h"

using namespace VMOS;

bool BNO055::Init(){
    i2cClient.setup(0x28);
}
/*
Will get ChipID from the BNO055.
Will return an interger version ChipID

-1 = Error
*/
int BNO055::GetChipID(){
    char chipId = 0;

    if(i2cClient.readData(chipId, CHIP_IP) != 0){
        Logging::Log("BNO055", "GetChipID", "Failed to get I2C Data");
        return -1;
    }

    return (int) chipId;

}

int BNO055::GetTempature(){
    char tempature;

    if(i2cClient.readData(tempature, TEMP) != 0){
        Logging::Log("BNO055", "GetTempature", "Failed to get I2C Data");
        return -1;
    }

    return (int) tempature;
}

Euler BNO055::GetFusedOrieentation(){
    Euler _orient;

    _orient.x = 10;
    _orient.y = 20;
    _orient.z = 30;

    return _orient;
}