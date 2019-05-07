#include <iostream>
#include "core/threading/message_queue.hpp"
#include "core/threading/queue_manager.hpp"
#include "core/logging/logging.hpp"
#include "testbed/systems/mock_subsystem.hpp"
#include <string>
#include <thread>
#include <unistd.h>
#include "testbed/systems/mock.pb.h"
using namespace VMOS;

int main(){
    
    VMOS::Logging::Log("TestBed", "main" , "VMOS Test Bed Running.");

    
    VMOS::TestBed::MockSubsystem mock1;
    std::thread mockThread1(std::ref(mock1));
    mockThread1.detach();

    MessageQueue<TestBed::MockSubsystemOutput>* queue =  VMOS::QueueManager<TestBed::MockSubsystemOutput>::fetch("mock-thread");
    for(;;){

        TestBed::MockSubsystemOutput message;
        queue->getLatest(message);
        VMOS::Logging::Log("TestBed", "main - Mock", "Test Tick: " + std::to_string(message.mock_tick()) + " / " + std::to_string(message.half_tick()));
        usleep(500000);
    }

    return 0;
}