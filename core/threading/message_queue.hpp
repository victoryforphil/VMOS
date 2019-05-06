#ifndef _MESSAGE_QUEUE_H_
#define _MESSAGE_QUEUE_H_
#include "core/math/euler.hpp"
#include <vector>
#include <memory>

template <typename T>
class MessageQueue{
    protected:
        std::unique_ptr<T> messages_;
        
    public:
        MessageQueue<T>(uint8_t len): messages_(new T[len]){ };
        T* getRef();
        T getValue(){return ;}
};


#endif