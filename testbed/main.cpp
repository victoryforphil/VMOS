#include <iostream>
#include "core/threading/threading.h"
#include "core/math/euler.hpp"
#include "hardware/sensors/BNO055.h"
#include "core/logging/logging.hpp"
int main(){
    Threading t;
    t.Run();
    
    VMOS::Logging::Log("TestBed", "main" , "VMOS Test Bed Running.");

    Euler imu_test = BNO055().GetFusedOrieentation();

    VMOS::Logging::Log("TestBed", "main", imu_test.ToString());

    for(;;){}
    return 0;
}