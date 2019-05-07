#include "mock_subsystem.hpp"
#include <unistd.h>
#include "testbed/systems/mock.pb.h"
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

    testbed::mock::MockSubsystemOutput output;
    output.tick = tickN;
    tickN++;
  
    queue->write(output);
}

