#include "http_client.h"

VMOS::HTTPClient::HTTPClient(char* host){
    mHost = host;
    mClient = new httplib::Client(host);
    Logging::Log("HTTPClient", "constructor", "Creating new HTTP Client for HOST:" + std::string(host));
}

int VMOS::HTTPClient::get(std::string path, std::string* result){

    /* Example code from Github
    auto res = cli.Get("/hi");
    if (res && res->status == 200) {
        std::cout << res->body << std::endl;
    }
    */
   
   auto res = mClient->Get(path.c_str());
   if(res && res->status == 200){
     
       *result = res->body;
   }else{
     
       return res->status || 1;
   }
    return 0;
}

