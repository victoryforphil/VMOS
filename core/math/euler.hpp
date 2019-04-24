#include <string>

enum EulerUnits {
    DEGREES = 0,
    RADIANS = 1
};

class Euler{
    public:
        double x,y,z;
        EulerUnits units = DEGREES;

        Euler(){
           x = 0;
           y = 0;
           z = 0;
        };
        Euler(double x,double y,double z){
            this->x = x;
            this->y = y;
            this->z = z;
        };

        std::string ToString();
};