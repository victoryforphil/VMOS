#ifndef _HTTP_CLIENT_H_
#define _HTTP_CLIENT_H_

#include "httplib.h"
#include <string>
#include "core/logging/logging.hpp"
namespace VMOS
{
    class HTTPClient
    {
    private:
        /* data */
        char* mHost;
        std::uint16_t mPort = 80;

        httplib::Client* mClient;
    public:
        HTTPClient(char* host);
        int get(std::string path, std::string* result);
     
    };

       
} // namespace VMOS


#endif