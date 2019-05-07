#ifndef _MOCK_SUBSYSTEM_H_
#define _MOCK_SUBSYSTEM_H_
#include <thread>
#include "core/threading/message_queue.hpp"
#include "core/threading/queue_manager.hpp"
namespace VMOS
{
    namespace TestBed
    {
        class MockSubsystem{
            private:
                int tickN = 0;
                std::thread* run_thread;
                MessageQueue<int>* queue;
                //TODO: Replace with Message Queue

            public:
                void operator()();
                //void init_tick();
                void tick();
              
               

        };
    } // TestBed
    
} // VMOS


#endif