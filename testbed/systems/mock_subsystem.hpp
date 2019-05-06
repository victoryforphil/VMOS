#ifndef _MOCK_SUBSYSTEM_H_
#define _MOCK_SUBSYSTEM_H_
#include <thread>
#include "core/threading/message_queue.hpp"
namespace VMOS
{
    namespace TestBed
    {
        class MockSubsystem{
            private:
               
                std::thread* run_thread;
                
                //TODO: Replace with Message Queue

            public:
                void operator()();
                //void init_tick();
                void tick();
              
               

        };
    } // TestBed
    
} // VMOS


#endif