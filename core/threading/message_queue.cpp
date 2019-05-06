#include "message_queue.hpp"
template <typename T>
MessageQueue<T>::MessageQueue(u_int8_t len) : messages_(new T[len]){}

template <typename T>
void MessageQueue<T>::getLatest(T* out){
    out = messages_[0];
}