#include <iostream>
#include "core/threading/message_queue.hpp"

#include "core/math/euler.hpp"
#include "core/math/conversions.hpp"
#include "hardware/sensors/BNO055.h"
#include "core/logging/logging.hpp"
#include "hardware/i2c/i2c.hpp"
#include "testbed/systems/sensor_subsystem.hpp"
#include <string>
#include <thread>
using namespace VMOS;

int main(){
    
    VMOS::Logging::Log("TestBed", "main" , "VMOS Test Bed Running.");


    VMOS::TestBed::SensorSubsystem senSys;
    std::thread sensorThread(std::ref(senSys));
    sensorThread.detach();

    Euler lastVal;
    for(;;){
        /*
        if(MessageQueue::getValue() != lastVal ){
            lastVal = MessageQueue::getValue();
            VMOS::Logging::Log("TestBed", "main - IMU",  MessageQueue::getValue().ToStringAreo());
        }
       
        //VMOS::Logging::Log("TestBed", "main - IMU", "IMU Orient: " + VMOS::TestBed::SensorSubsystem::angel->ToString());
        */
    }

    return 0;
}