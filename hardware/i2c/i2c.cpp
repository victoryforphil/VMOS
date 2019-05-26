#include "i2c.hpp"
#include "core/logging/logging.hpp"
using namespace VMOS;

int I2C::setup( int addr)
{
    Logging::Log("I2C", "const", "Starting new I2C Client at: " +std::to_string(addr));

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
   
    unsigned char result;
    
    writeData(reg, 0x00);
    
    if(read(file, &result, 1) != 1){
        return 1;
    }
	
   
    out = result;
    return 0;
    
}


int I2C::writeData(char reg, char data){
    char buffer[] = {reg, data};
    if (write(file, &buffer, 2) != 2)		//write() returns the number of bytes actually written, if it doesn't match then an error occurred (e.g. no response from the device)
	{
		/* ERROR HANDLING: i2c transaction failed */
		
        return 1;
	}

 
    return 0;
}