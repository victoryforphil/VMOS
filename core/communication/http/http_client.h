#ifndef _HTTP_CLIENT_H_
#define _HTTP_CLIENT_H_

#include "httplib.h"
#include <string>
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
        int get(char* path, char** result);
        
        ~HTTPClient();
    };

       
} // namespace VMOS


#endif