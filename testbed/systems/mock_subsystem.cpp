#include "mock_subsystem.hpp"
#include <unistd.h>
using namespace VMOS;
using namespace TestBed;



void VMOS::TestBed::MockSubsystem::operator()()
{
   
    while (true)
    {
        tick();
        usleep(10000); // 10ms (100hz)
      
    }
}



void VMOS::TestBed::MockSubsystem::tick()
{
   
}
