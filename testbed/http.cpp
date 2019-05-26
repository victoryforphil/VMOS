#include <iostream>
#include "core/logging/logging.hpp"
#include <string>
#include <thread>
#include "core/communication/http/http_client.h"

using namespace VMOS;

int main(){
    
    VMOS::Logging::Log("TestBed", "main" , "VMOS Test Bed Running.");

    char* http_res = "";
    HTTPClient client("https://httpbin.org", http_res);
    int result = client.get("/get", &http_res);
    if(result == 0){
        std::cout << "HTTP RESULT: " + http_res << std::endl;
    }else{
        VMOS::Logging::Log("TestBed-HTTP", "main", "HTTP ERROR");
    }
    return 0;
}