#ifndef _MESSAGE_QUEUE_H_
#define _MESSAGE_QUEUE_H_
#include "core/math/euler.hpp"
class MessageQueue{
    private:
        static Euler testEuler;

    public:
        static Euler* getRef();
        static Euler getValue(){return testEuler;}
};


#endif