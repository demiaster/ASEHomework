#include <iostream>
#include <cstdlib>
#include <cmath>
#include <fstream>

int main(int argc, char ** argv)
{
    std::cout<<"# Insert frequency \n";
    double frequency;
    std::cin>>frequency;
    std::cout<<"# Insert amplitude \n";
    double amplitude;
    std::cin>>amplitude;
    std::ofstream fileOut;
    fileOut.open(argv[1]);
    // check to see if we can open the file
    if (!fileOut.is_open())
    {
        std::cerr <<"Could not open File : "<<argv[1]<<" for writing \n";
        exit(EXIT_FAILURE);
    }
    fileOut<<"# X YS YC\n";
    const double step = 0.01;
    const double range = 5;
    for(double x=0; x<range; x+=0.1)
    {
        double ys=amplitude*sin(frequency*M_PI*x);
        double yc=amplitude*cos(frequency*M_PI*x);
        fileOut<< x <<' '<< ys <<' '<< yc <<'\n';
    }
    fileOut.close();
    return EXIT_SUCCESS;
}