#include <iostream>
#include <cstdlib>
#include <random>
#include <cmath>

int main()
{
    std::cerr<<"# Insert frequency \n";
    double frequency;
    std::cin>>frequency;
    std::cerr<<"# Insert amplitude \n";
    double amplitude;
    std::cin>>amplitude;
    std::cout<<"# X YS YC\n";
    const double step = 0.01;
    const double range = 5;
    for(double x=0; x<range; x+=0.1)
    {
        double ys=amplitude*sin(frequency*M_PI*x);
        double yc=amplitude*cos(frequency*M_PI*x);
        std::cout<< x <<' '<< ys <<' '<< yc <<'\n';
    }
    return EXIT_SUCCESS;
}