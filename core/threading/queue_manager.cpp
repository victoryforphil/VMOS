/*

#include "queue_manager.hpp"

using namespace VMOS;
template <typename T>
std::unordered_map<std::string, MessageQueue<T>> QueueManager<T>::allQueues_;


template <typename T>
MessageQueue<T>* QueueManager<T>::fetch(char* name)
{
    auto found = allQueues_.find(name);
    if (found == allQueues_.end())
    {
        auto inserted = allQueues_.emplace(name, MessageQueue<T>(100));
        found = inserted.first;
    }

    return &found->second;
}
*/