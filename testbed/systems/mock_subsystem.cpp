#include "mock_subsystem.hpp"
#include <unistd.h>
using namespace VMOS;
using namespace TestBed;


 
void VMOS::TestBed::MockSubsystem::operator()()
{
    queue = VMOS::QueueManager<int>::fetch("mock-thread");

    while (true)
    {
        tick();
        usleep(10); // 1ms (1000hz)
      
    }
}



void VMOS::TestBed::MockSubsystem::tick()
{
    tickN++;
    queue->write(tickN);
}

