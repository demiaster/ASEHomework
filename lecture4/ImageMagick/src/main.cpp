#include "Image.h"
#include <cstdlib>
#include <iostream>

// random shits
#include <random>
#include <algorithm>
#include <sstream>

constexpr int WIDTH = 1920;
constexpr int HEIGHT = 1080;
constexpr int DEPTH = 3;

void rnd(int);

int main()
{
  std::cout<<"Need to write an Image Class\n";
  Image image(WIDTH, HEIGHT, DEPTH);
  image.clearScreen(67, 189, 242);
  image.save("picture.png");

  for (int i = 0; i < 50; ++i)
    rnd(i);
  // Create a video with: ffmpeg -i picture-$DISTRIBUTION-%d.png output.gif

  return EXIT_SUCCESS;
}

/* Investigate the C++ 11 random functions to create
 * random images using the different distributions
 */
#define NORMAL 1
#ifdef NORMAL
#define DISTRIBUTION std::normal_distribution<double> distribution(128,128)
#define NORMALIZE (unsigned int)distribution(generator) % 255
#define DSTRING "normal"
#elif GAMMA
#define DISTRIBUTION std::gamma_distribution<char> distribution(2.0,2.0)
#define DSTRING "gamma"
#endif
//#define STEP ((distribution.max() - distribution.min()) / 255)
//#define NORMALIZE (distribution(generator) - distribution.min()) / STEP


void rnd(int output)
{
    static std::knuth_b generator;
    DISTRIBUTION;
    Image image(WIDTH, HEIGHT, DEPTH);

    std::cout << NORMALIZE << "\n";
    std::cout << NORMALIZE << "\n";
    std::cout << NORMALIZE << "\n";
    std::cout << NORMALIZE << "\n";
    std::cout << NORMALIZE << "\n";
    std::cout << NORMALIZE << "\n";

    for (unsigned int i = 0; i < WIDTH; ++i)
    {
        for (unsigned int j = 0; j < HEIGHT; ++j) {
            std::vector<unsigned char> vec;
            vec.push_back(NORMALIZE);
            vec.push_back(NORMALIZE);
            vec.push_back(NORMALIZE);
            std::sort(vec.begin(), vec.begin());

            image.setPixel(i, j, vec.at(0),
                           vec.at(1),
                           vec.at(2));
        }
    }
    std::stringstream ss;
    ss << "picture-" << DSTRING << "-" << output << ".png";
    image.save(ss.str().c_str());
}

/* write a program to animate a simple line crossing the screen,
 * by outputing multiple frames to disc (hint use a loop and
 * sprintf to write the filename out) you can use fcheck or
 * animate to show the frames
 */
void lines()
{

}

/* Investigate the use of fmod to create repeating patterns
 *  such as a sphere
 */
void repeatingPatterns()
{

}
