#include <iostream>
#include "core/threading/message_queue.hpp"
#include "core/threading/queue_manager.hpp"
#include "core/logging/logging.hpp"
#include "testbed/systems/mock_subsystem.hpp"
#include <string>
#include <thread>
using namespace VMOS;

int main(){
    
    VMOS::Logging::Log("TestBed", "main" , "VMOS Test Bed Running.");


    VMOS::TestBed::MockSubsystem mock;
    std::thread mockThread(std::ref(mock));
    mockThread.detach();
    
    VMOS::QueueManager<int>::fetch("Test");
    for(;;){

       
        //VMOS::Logging::Log("TestBed", "main - IMU", "IMU Orient: " + VMOS::TestBed::SensorSubsystem::angel->ToString());

    }

    return 0;
}