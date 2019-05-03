#include  "logging.hpp"

using namespace VMOS;

std::string Logging::Log(std::string source, std::string method, std::string data){
    std::string _toPrint = "[ LOG ] " + source + "/" + method + " -> " + data;

    std::cout << _toPrint << std::endl;

    return _toPrint;
}