#include "BNO055.h"

using namespace VMOS;

bool BNO055::Init(){
   return BNO055::Init(BNO055Mode::NDOF);
}

bool BNO055::Init(BNO055::BNO055Mode operationMode){
    i2cClient.setup(0x28);
    i2cClient.writeData(OPR_MODE, operationMode);

    return true;
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

int BNO055::GetAccID(){
    char accId = 0;

    if(i2cClient.readData(accId, ACC_ID) != 0){
        Logging::Log("BNO055", "GetAccID", "Failed to get I2C Data");
        return -1;
    }

    return (int) accId;
}

int BNO055::GetGyrID(){
    char chipId = 0;

    if(i2cClient.readData(chipId, GYR_ID) != 0){
        Logging::Log("BNO055", "GetGyrID", "Failed to get I2C Data");
        return -1;
    }

    return (int) chipId;
}

int BNO055::GetMagID(){
    char magId = 0;

    if(i2cClient.readData(magId, MAG_ID) != 0){
        Logging::Log("BNO055", "GetMagID", "Failed to get I2C Data");
        return -1;
    }

    return (int) magId;
}


int BNO055::GetTempature(){
    char tempature;

    if(i2cClient.readData(tempature, TEMP) != 0){
        Logging::Log("BNO055", "GetTempature", "Failed to get I2C Data");
        return -1;
    }

    return (int) tempature;
}


int BNO055::GetFusedOrientation(Euler* orientation){
  

    char headingLSB, headingMSB, rollLSB, rollMSB, pitchLSB, pitchMSB;

    if(i2cClient.readData(headingLSB, EUL_Heading_LSB) != 0){
        Logging::Log("BNO055", "GetFusedOrientation", "Failed to get I2C Data");
        return 1;
    }

    if(i2cClient.readData(headingMSB, EUL_Heading_MSB) != 0){
        Logging::Log("BNO055", "GetFusedOrientation", "Failed to get I2C Data");
        return 1;
    }



    if(i2cClient.readData(rollLSB, EUL_Roll_LSB) != 0){
        Logging::Log("BNO055", "GetFusedOrientation", "Failed to get I2C Data");
        return 1;
    }

    if(i2cClient.readData(rollMSB, EUL_Roll_MSB) != 0){
        Logging::Log("BNO055", "GetFusedOrientation", "Failed to get I2C Data");
        return 1;
    }



    if(i2cClient.readData(pitchLSB, EUL_Pitch_LSB) != 0){
        Logging::Log("BNO055", "GetFusedOrientation", "Failed to get I2C Data");
        return 1;
    }

    if(i2cClient.readData(pitchMSB, EUL_Pitch_MSB) != 0){
        Logging::Log("BNO055", "GetFusedOrientation", "Failed to get I2C Data");
        return 1;
    }

    
    orientation->setYaw((headingLSB | (headingMSB << 8) ) / 16);
    orientation->setRoll((rollLSB | (rollMSB << 8) ) / 16);
    orientation->setPitch((pitchLSB | (pitchMSB << 8) ) / 16);
    

    return 0;
}