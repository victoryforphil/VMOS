#include "mock_subsystem.hpp"
#include <unistd.h>

#include <google/protobuf/arena.h>

using namespace VMOS;
using namespace TestBed;


 
void VMOS::TestBed::MockSubsystem::operator()()
{   
    
    queue = VMOS::QueueManager<MockSubsystemOutput>::fetch("mock-thread");

    while (true)
    {
        tick();
        usleep(10); // 1ms (1000hz)
      
    }
}



void VMOS::TestBed::MockSubsystem::tick()
{
    
    MockSubsystemOutput output;
    output.set_mock_tick(tickN);
    output.set_half_tick(tickN / 2);
    tickN++;
  
    queue->write(output);
}

