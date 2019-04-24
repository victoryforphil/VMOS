#include <iostream>
#include "core/threading/threading.h"
#include "core/math/euler.hpp"
#include "hardware/sensors/BNO055.h"
int main(){
    Threading t;
    t.Run();
    std::cout << "VMS Hello World" << std::endl;

    Euler imu(10,10,10);

    std::cout << imu.ToString() << std::endl;

    for(;;){}
    return 0;
}