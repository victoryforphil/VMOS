#include <iostream>
#include "core/logging/logging.hpp"
#include <string>
#include <thread>
#include "core/communication/http/http_client.h"

using namespace VMOS;

int main(){
    
    VMOS::Logging::Log("TestBed-HTTP", "main" , "VMOS Test Bed Running.");

    std::string http_res = "";
    HTTPClient client("jsonplaceholder.typicode.com");

    int result = client.get("/todos/1", &http_res);
    if(result == 0){
        std::cout << "HTTP RESULT: " << http_res << std::endl;
    }else{
        VMOS::Logging::Log("TestBed-HTTP", "main", "HTTP ERROR: " + std::to_string(result));
    }
    return 0;
}