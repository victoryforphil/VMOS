#include "euler.hpp"

std::string Euler::ToString(){
    return "Euler: x=" + std::to_string(x) + ", y=" + std::to_string(y) + ", z=" + std::to_string(z) ;
}

std::string Euler::ToStringAreo(){
    return "Euler: roll=" + std::to_string(x) + ", pitch=" + std::to_string(y) + ", yaw=" + std::to_string(z) ;
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

bool Euler::operator==(Euler& other) const{
    double diffX = abs(x - other.x);
    double diffY = abs(y - other.y);
    double diffZ = abs(z - other.z);
    return (diffX + diffY + diffZ ) / 3 < 0.1;
}

bool Euler::operator!=(Euler& other) const{
    double diffX = abs(x - other.x);
    double diffY = abs(y - other.y);
    double diffZ = abs(z - other.z);
    return (diffX + diffY + diffZ ) / 3 > 0.1;
}