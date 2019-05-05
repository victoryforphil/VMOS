#include "conversions.hpp"

using namespace VMOS;

double VMOS::Conversions::celiusToFahrenhiet(double celius){
    return celius * 1.8 + 32 ;
}