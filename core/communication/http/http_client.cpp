#include "http_client.h"

VMOS::HTTPClient::HTTPClient(char* host){
    mHost = host;
    mClient = new httplib::Client(host,mPort, 300L);
}

int VMOS::HTTPClient::get(char* path, char** result){

    /* Example code from Github
    auto res = cli.Get("/hi");
    if (res && res->status == 200) {
        std::cout << res->body << std::endl;
    }
    */

   auto res = mClient->Get(path);
   if(res && res->status == 200){
       *result = (char*) &res->body[0u];
   }else{
       
       return 1;
   }
    return 0;
}

