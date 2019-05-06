#ifndef _MESSAGE_QUEUE_H_
#define _MESSAGE_QUEUE_H_
#include "core/math/euler.hpp"
#include <vector>
#include <memory>

template <typename T>
class MessageQueue{
    private:
        std::unique_ptr<T[]> messages_;
        
    public:
        explicit MessageQueue(uint8_t len);
        void getLatest(T* out);
};


#endif