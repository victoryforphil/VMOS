#ifndef _QUEUE_MANAGER_H
#define _QUEUE_MANAGER_H
#include "message_queue.hpp"
#include <unordered_map>
#include <string>
namespace VMOS
{   
    template <typename T>
    class QueueManager{
        private:
            static std::unordered_map<std::string, MessageQueue<T>> allQueues_;
        public:
            static MessageQueue<T>* fetch(const char* name);
    };

    template <typename T>
    std::unordered_map<std::string, MessageQueue<T>> QueueManager<T>::allQueues_;
    
    template <typename T>
    MessageQueue<T>* QueueManager<T>::fetch(const char* name){

    }
} // VMOS


#endif