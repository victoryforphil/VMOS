#include "VL53L1X.hpp"

using namespace VMOS;

static VL53L1_RangingMeasurementData_t RangingMeasurementData;
static VL53L1_RangingMeasurementData_t *pRangingMeasurementData = &RangingMeasurementData;

int VMOS::VL53L1X::i2cRead(uint8_t address, uint8_t reg, uint8_t *list, uint8_t length)
{
     
     int status = 0;
     char *path = (char *)"/dev/i2c-1";
     int file;
     /*

     std::cout << "Reading from slave: " << std::hex << (int)address;
     std::cout << " Addres: " << std::hex << (int)reg << std::endl;
     */

     if ((file = open(path, O_RDWR)) < 0)
     {
          Logging::Log("I2C", "setup", "Failed to open I2C File");
          close(file);
          return -1;
     }

     if (ioctl(file, I2C_SLAVE, address) < 0)
     {
          Logging::Log("I2C", "setup", "Failed to talk to I2C Slave");
          return 2;
     }
     uint8_t addr[2];
     addr[0] = reg >> 8;
     addr[1] = reg & 0xff;
     write(file, addr, 2);
     read(file, list, length);
     close(file);
     return status;
}
int VMOS::VL53L1X::i2cWrite(uint8_t address, uint8_t reg, uint8_t *list, uint8_t length)
{

     int status = 0;
     char *path = (char *)"/dev/i2c-1";
     int file;
     /*

     std::cout << "Reading from slave: " << std::hex << (int)address;
     std::cout << " Addres: " << std::hex << (int)reg << std::endl;
     */

     if ((file = open(path, O_RDWR)) < 0)
     {
          Logging::Log("I2C", "setup", "Failed to open I2C File");
          close(file);
          return -1;
     }

     if (ioctl(file, I2C_SLAVE, address) < 0)
     {
          Logging::Log("I2C", "setup", "Failed to talk to I2C Slave");
          return 2;
     }

     char data[200];
     data[0] = reg >> 8;
     data[1] = reg & 0xff;
     for (int i = 0; i < length; i++)
     {
          data[i + 2] = list[i];
     }
     write(file, data, 2 + length);
     close(file);
     return status;
}

int VMOS::VL53L1X::Init(u_int8_t address)
{

     usleep(5000);

     VL53L1_set_i2c((void *)&VMOS::VL53L1X::i2cRead, (void *)&VMOS::VL53L1X::i2cWrite);

     VL53L1_Error Status = VL53L1_ERROR_NONE;
     uint32_t refSpadCount;
     uint8_t isApertureSpads;
     uint8_t VhvSettings;
     uint8_t PhaseCal;
     VL53L1_Version_t Version;
     VL53L1_Version_t *pVersion = &Version;
     VL53L1_DeviceInfo_t DeviceInfo;
     int32_t status_int;

     mDev = (VL53L1_Dev_t *)malloc(sizeof(VL53L1_Dev_t));
     memset(mDev, 0, sizeof(VL53L1_Dev_t));

     mDev->I2cDevAddr = address;

     Status = VL53L1_software_reset(mDev);
     Status = VL53L1_WaitDeviceBooted(mDev);
     Status = VL53L1_DataInit(mDev);
     Status = VL53L1_StaticInit(mDev);
     if (Status == VL53L1_ERROR_NONE)
     {
          Status = VL53L1_GetDeviceInfo(mDev, &DeviceInfo);
          if (Status == VL53L1_ERROR_NONE)
          {
               printf("VL53L0X_GetDeviceInfo:\n");
               printf("Device Name : %s\n", DeviceInfo.Name);
               printf("Device Type : %s\n", DeviceInfo.Type);
               printf("Device ID : %s\n", DeviceInfo.ProductId);
               printf("ProductRevisionMajor : %d\n", DeviceInfo.ProductRevisionMajor);
               printf("ProductRevisionMinor : %d\n", DeviceInfo.ProductRevisionMinor);
          }
     }
     else
     {
          printf("Error Ini Init: %d \n ", Status);
     }
     std::cout << "VL53L1_PerformRefSpadManagement" << std::endl;

     VL53L1_PerformRefSpadManagement(mDev);
     std::cout << "VL53L1_SetXTalkCompensationEnable" << std::endl;
     VL53L1_SetXTalkCompensationEnable(mDev, 0); // Disable crosstalk compensation (bare sensor)

     return 0;
}

int VMOS::VL53L1X::SetI2CAddress(u_int8_t newAddress)
{
     return 0;
}

int VMOS::VL53L1X::StartRanging()
{
     VMOS::Logging::Log("VL53L1X", "Start Ranging", "starting to range");
     VL53L1_Error Status = VL53L1_ERROR_NONE;
     Status = VL53L1_SetDistanceMode(mDev, 1);
     Status = VL53L1_SetMeasurementTimingBudgetMicroSeconds(mDev, 66000);
     Status = VL53L1_SetInterMeasurementPeriodMilliSeconds(mDev, 70);
     Status = VL53L1_StartMeasurement(mDev);
     return Status;
}

int VMOS::VL53L1X::StopRanging()
{
     return 0;
}

int VMOS::VL53L1X::GetDistance(int32_t *distance)
{
     VL53L1_Error Status = VL53L1_ERROR_NONE;
     int32_t current_distance = -1;
     Status = VL53L1_WaitMeasurementDataReady(mDev);
     Status = VL53L1_GetRangingMeasurementData(mDev, pRangingMeasurementData);
     current_distance = pRangingMeasurementData->RangeMilliMeter;

     VL53L1_ClearInterruptAndStartMeasurement(mDev);

     *distance = current_distance;
     return Status;
}