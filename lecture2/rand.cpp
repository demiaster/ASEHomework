/// to compile use clang++ -Wall -g -std=c++11  random.cpp -o rand
#include <iostream>
#include <cstdlib>
#include <random>

int main()
{
  std::random_device rd;
  std::default_random_engine randEngine(rd()) ;
  std::uniform_real_distribution<> dist(-10, 10);

  std::cout<<"# X Y Z\n";
  for(int i=0; i<200; ++i)
  {
    std::cout<<dist(randEngine)<<' '<<dist(randEngine)<<' '<<dist(randEngine)<<'\n';
  }
  return EXIT_SUCCESS;
}
