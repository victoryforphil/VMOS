#ifndef _VMOS_LOGGING_H_
#define _VMOS_LOGGING_H_

#include <iostream>
#include <string>
namespace VMOS{
    class Logging{
      public:
        static std::string Log(std::string source, std::string method, std::string data);
    };
};

#endif