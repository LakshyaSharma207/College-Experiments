#include <iostream>
#include <math.h>

inline float Vcube()
{
    float a;
    std::cout << "Enter edge of cube = ";
    std::cin >> a;
    return pow(a,3);
}

inline float Vsphere(){
    float b;
    std::cout << "\nEnter radius of sphere = ";
    std::cin >> b;
    return 4*3.14*pow(b,3)/3;
}

inline float Vcylin()
{
    float r,h;
    std::cout << "\nEnter radius of cylinder = ";
    std::cin >> r;
    std::cout << "\nEnter height of cylinder = ";
    std::cin >> h;
    return 3.14*h*pow(r,2);
}

inline float Vcone()
{
    float r,h;
    std::cout << "\nEnter radius of cone = ";
    std::cin >> r;
    std::cout << "\nEnter height of cone = ";
    std::cin >> h;
    return 3.14*h*pow(r,2)/3;
}

int main()
{
    float finalcube = Vcube();
    std::cout << "Volume of cube is = " << finalcube;
    
    float finalS = Vsphere();
    std::cout << "Volume of sphere is = " << finalS;
    
    float finalV = Vcylin();
    std::cout << "Volume of cylinder is = " << finalV;
    
    float finalcone = Vcone();
    std::cout << "Volume of cylinder is = " << finalcone;
}
