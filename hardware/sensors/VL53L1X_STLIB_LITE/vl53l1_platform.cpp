
/* 
* This file is part of VL53L1 Platform 
* 
* Copyright (c) 2016, STMicroelectronics - All Rights Reserved 
* 
* License terms: BSD 3-clause "New" or "Revised" License. 
* 
* Redistribution and use in source and binary forms, with or without 
* modification, are permitted provided that the following conditions are met: 
* 
* 1. Redistributions of source code must retain the above copyright notice, this 
* list of conditions and the following disclaimer. 
* 
* 2. Redistributions in binary form must reproduce the above copyright notice, 
* this list of conditions and the following disclaimer in the documentation 
* and/or other materials provided with the distribution. 
* 
* 3. Neither the name of the copyright holder nor the names of its contributors 
* may be used to endorse or promote products derived from this software 
* without specific prior written permission. 
* 
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" 
* AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE 
* IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE 
* DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE 
* FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL 
* DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR 
* SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER 
* CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, 
* OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE 
* OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE. 
* 
*/

#include "vl53l1_platform.h"
#include <string.h>
#include <time.h>
#include <linux/i2c-dev.h>
#include <unistd.h>    //Needed for I2C port
#include <fcntl.h>     //Needed for I2C port
#include <sys/ioctl.h> //Needed for I2C port
#include <math.h>

static int8_t i2c_write(uint16_t dev, uint8_t reg, uint8_t *data, uint8_t len)
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
		
		close(file);
		return -1;
	}

	if (ioctl(file, I2C_SLAVE, dev) < 0)
	{
		
		return 2;
	}

	char dataB[200];
	dataB[0] = reg >> 8;
	dataB[1] = reg & 0xff;
	for (int i = 0; i < len; i++)
	{
		dataB[i + 2] = data[i];
	}
	write(file, dataB, 2 + len);
	close(file);
	return 0;
}

static int8_t i2c_read(uint16_t dev, uint8_t reg, uint8_t *data, uint8_t len)
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
		
		close(file);
		return -1;
	}

	if (ioctl(file, I2C_SLAVE, dev) < 0)
	{
		close(file);
		return 2;
	}
	uint8_t addr[2];
	addr[0] = reg >> 8;
	addr[1] = reg & 0xff;
	write(file, addr, 2);
	read(file, data, len);
	close(file);
}

int8_t VL53L1_WriteMulti(uint16_t dev, uint16_t index, uint8_t *pdata, uint32_t count)
{
	return i2c_write(dev, index, pdata, count);
	
}

int8_t VL53L1_ReadMulti(uint16_t dev, uint16_t index, uint8_t *pdata, uint32_t count)
{
	return i2c_read(dev, index, pdata, count);
	
}

int8_t VL53L1_WrByte(uint16_t dev, uint16_t index, uint8_t data)
{
	return i2c_write(dev, index, &data, 1); // to be implemented
}

int8_t VL53L1_WrWord(uint16_t dev, uint16_t index, uint16_t data)
{
	uint8_t buf[4];
	buf[1] = data >> 0 & 0xFF;
	buf[0] = data >> 8 & 0xFF;
	return i2c_write(dev, index, buf, 2);
}

int8_t VL53L1_WrDWord(uint16_t dev, uint16_t index, uint32_t data)
{
	uint8_t buf[4];
	buf[3] = data >> 0 & 0xFF;
	buf[2] = data >> 8 & 0xFF;
	buf[1] = data >> 16 & 0xFF;
	buf[0] = data >> 24 & 0xFF;
	return i2c_write(dev, index, buf, 4);
}

int8_t VL53L1_RdByte(uint16_t dev, uint16_t index, uint8_t *data)
{
	uint8_t tmp = 0;
	int ret = i2c_read(dev, index, &tmp, 1);
	*data = tmp;
	return ret;
}

int8_t VL53L1_RdWord(uint16_t dev, uint16_t index, uint16_t *data)
{
	uint8_t buf[2];
	int ret = i2c_read(dev, index, buf, 2);
	uint16_t tmp = 0;
	tmp |= buf[1] << 0;
	tmp |= buf[0] << 8;
	*data = tmp;
	return ret;
}

int8_t VL53L1_RdDWord(uint16_t dev, uint16_t index, uint32_t *data)
{
	uint8_t buf[4];
	int ret = i2c_read(dev, index, buf, 4);
	uint32_t tmp = 0;
	tmp |= buf[3] << 0;
	tmp |= buf[2] << 8;
	tmp |= buf[1] << 16;
	tmp |= buf[0] << 24;
	*data = tmp;
	return ret;
}

int8_t VL53L1_WaitMs(uint16_t dev, int32_t wait_ms)
{
	usleep(wait_ms * 1000);
	return 0; // to be implemented
}
