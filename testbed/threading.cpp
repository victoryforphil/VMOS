#include <iostream>
#include "core/threading/message_queue.hpp"
#include "core/threading/queue_manager.hpp"
#include "core/logging/logging.hpp"
#include "testbed/systems/mock_subsystem.hpp"
#include <string>
#include <thread>
#include <unistd.h>
using namespace VMOS;

int main(){
    
    VMOS::Logging::Log("TestBed", "main" , "VMOS Test Bed Running.");


    VMOS::TestBed::MockSubsystem mock1;
    std::thread mockThread1(std::ref(mock1));
    mockThread1.detach();

    MessageQueue<int>* queue =  VMOS::QueueManager<int>::fetch("mock-thread");
    for(;;){

        int val = 0;
        queue->getLatest(val);
        VMOS::Logging::Log("TestBed", "main - Mock", "Test Tick: " + std::to_string(val));
        usleep(500000);
    }

    return 0;
}