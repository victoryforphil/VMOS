#include "i2c.hpp"
#include "core/logging/logging.hpp"
using namespace VMOS;

int I2C::setup( int addr)
{
    Logging::Log("I2C", "const", "Starting new I2C Client at: ");

    if ((file = open(path, O_RDWR)) < 0)
    {
        Logging::Log("I2C", "setup", "Failed to open I2C File");
        return 1;
    }

  
    if (ioctl(file, I2C_SLAVE, addr) < 0)
    {
        Logging::Log("I2C", "setup", "Failed to talk to I2C Slave");
        return 2;
    }
    Logging::Log("I2C", "const", "Started");
    return 0;
}

int I2C::readData(char &out, char reg){
    int length = 1;			//<<< Number of bytes to read
    unsigned char buffer[length] = {0};
    
	if (write(file, &reg, 1) != 1)		//write() returns the number of bytes actually written, if it doesn't match then an error occurred (e.g. no response from the device)
	{
		/* ERROR HANDLING: i2c transaction failed */
		printf("Failed to write to the i2c bus.\n");
        return 1;
	}
   
	if (read(file, buffer, length) != length)		//read() returns the number of bytes actually read, if it doesn't match then an error occurred (e.g. no response from the device)
	{
		//ERROR HANDLING: i2c transaction failed
		Logging::Log("I2C", "setup", "Failed to read I2C");
        return 2;
	}
    
    out = buffer[0];
    return 0;
    
}