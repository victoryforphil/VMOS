#ifndef _EULER_H_
#define _EULER_H_

#include <string>


class Euler{
    public:
        double x,y,z;
       

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

        void setYaw(double val);
        void setPitch(double val);
        void setRoll(double val);

        bool operator==(Euler& other) const;
        bool operator!=(Euler& other) const;

        std::string ToString();
        std::string ToStringAreo();

};

#endif