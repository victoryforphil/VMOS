#include "euler.hpp"

std::string Euler::ToString(){
    return "Euler: x=" + std::to_string(x) + ", y=" + std::to_string(y) + ", z=" + std::to_string(z) ;
}

void Euler::setYaw(double val){
    this->z = val;
}

void Euler::setPitch(double val){
    this->y = val;
}

void Euler::setRoll(double val){
    this->x = val;
}