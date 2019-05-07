#ifndef _MESSAGE_QUEUE_H_
#define _MESSAGE_QUEUE_H_
#include "core/math/euler.hpp"
#include <vector>
#include <memory>
#include <iostream>
template <typename T>
class MessageQueue{
    private:
        std::unique_ptr<T[]> messages_;
        int index = 0;
        u_int8_t size_ = 0;
        
    public:
        explicit MessageQueue(uint8_t len);
        
        void getLatest(T& out);

        void write(const T data);
};

template <typename T>
MessageQueue<T>::MessageQueue(u_int8_t len) : messages_(new T[len]), size_(len){}

template <typename T>
void MessageQueue<T>::getLatest(T& out){
    
    out = messages_[index - 1];
}

template <typename T>
void MessageQueue<T>::write(const T data){

    messages_[index] = data;
    
    
    if(index >= size_ - 1){
        for(int i=1;i < size_ + 1;i++){
            messages_[i - 1] = messages_[i];
        }
    
    }else{
        index += 1;
    }
}

#endif