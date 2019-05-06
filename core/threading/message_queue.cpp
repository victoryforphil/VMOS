#include "message_queue.hpp"

Euler MessageQueue::testEuler;

Euler* MessageQueue::getRef(){
    return &testEuler;
}