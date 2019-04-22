#include <iostream>
#include "threading/threading.h"
#include "math/euler.hpp"
int main(){
    Threading t;
    t.Run();
    std::cout << "VMS Hello World" << std::endl;

    Euler imu(10,10,10);

    

    for(;;){}
    return 0;
}