#include <iostream>
#include "core/logging/logging.hpp"
#include <string>
#include <thread>
#include "core/communication/sockets/tcp_server.hpp"

using namespace VMOS;

int main(){
    
    VMOS::Logging::Log("TestBed-HTTP", "main" , "VMOS Test Bed Running.");

   
    TCPServer server();

    return 0;
}