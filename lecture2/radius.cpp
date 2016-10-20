#include <iostream>
#include <cstdlib>
#include <random>
#include <cmath>

int main()
{
    std::cerr<<"# Insert radius \n";
    double radius;
    std::cin>>radius;
    std::cout<<"# X Y \n";
    const double step = 0.01;
    for(double t=0.0; t<=2 * M_PI; t+=step)
    {
        double x = radius*cos(t);
        double y = radius*sin(t);
        std::cout<< x <<' '<< y <<'\n';
    }
    return EXIT_SUCCESS;
}
