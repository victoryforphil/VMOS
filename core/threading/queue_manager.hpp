#ifndef _QUEUE_MANAGER_H
#define _QUEUE_MANAGER_H
#include "message_queue.hpp"
#include <unordered_map>
#include "core/logging/logging.hpp"
#include <string>
namespace VMOS
{
template <typename T>
class QueueManager
{
  private:
    static std::unordered_map<std::string, MessageQueue<T>> allQueues_;

  public:
    static MessageQueue<T>* fetch(const char *name);
};

template <typename T>
std::unordered_map<std::string, MessageQueue<T>> QueueManager<T>::allQueues_;

template <typename T>
MessageQueue<T>* QueueManager<T>::fetch(const char *name)
{
    auto found = allQueues_.find(name);
    if (found == allQueues_.end())
    {
        VMOS::Logging::Log("QueueManager", "fetch", "Creating new Queue: " + std::string(name));
        auto inserted = allQueues_.emplace(name, MessageQueue<T>(100));
        found = inserted.first;
    }

    return &(found->second);
}
} // namespace VMOS

#endif