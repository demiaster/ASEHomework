#include "Image.h"
#include <cstdlib>
#include <iostream>

// random shits
#include <random>
#include <algorithm>
#include <sstream>

//line things
#include <cmath>
#include <cassert>

constexpr int WIDTH = 1920;
constexpr int HEIGHT = 1080;
constexpr int DEPTH = 3;

void rnd(int);

void line(const unsigned int _startX, const unsigned int _startY,
           const unsigned int _endX, const unsigned int _endY,
           const unsigned char _r, const unsigned char _g, const unsigned char _b);

int main()
{
  std::cout<<"Need to write an Image Class\n";
  Image image(WIDTH, HEIGHT, DEPTH);
  image.clearScreen(67, 189, 242);
  image.save("picture.png");

  //for (int i = 0; i < 50; ++i)
  //    rnd(i);
  // Create a video with: ffmpeg -i picture-$DISTRIBUTION-%d.png output.gif

  line(100, 100, 800, 800, 255, 0, 0);

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


void rnd(const int output)
{
    static std::knuth_b generator;
    DISTRIBUTION;
    Image image(WIDTH, HEIGHT, DEPTH);
    for (unsigned int i = 0; i < WIDTH; ++i)
    {
        for (unsigned int j = 0; j < HEIGHT; ++j)
        {
            //just to get a more blue-ish result :)
            //maybe it gets things much slower
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
/* Breseham's line algorithm
 *  function line(x0, y0, x1, y1)
 *    real deltax := x1 - x0
 *    real deltay := y1 - y0
 *    real error := -1.0
 *    real deltaerr := abs(deltay / deltax)    // Assume deltax != 0 (line is not vertical),
 *          // note that this division needs to be done in a way that preserves the fractional part
 *    int y := y0
 *    for x from x0 to x1-1
 *        plot(x,y)
 *        error := error + deltaerr
 *        if error ≥ 0.0 then
 *            y := y + 1
 *            error := error - 1.0
 */
void line(const unsigned int _startX, const unsigned int _startY,
           const unsigned int _endX, const unsigned int _endY,
           const unsigned char _r, const unsigned char _g, const unsigned char _b)
{
    Image image(WIDTH, HEIGHT);

    //check input validity
    assert(0 < _startX && _startX < WIDTH);
    assert(0 < _endX && _endX < WIDTH);
    assert(0 < _startY && _startY < HEIGHT);
    assert(0 < _endY && _endY < HEIGHT);

    int deltaX = _endX - _startX;
    int deltaY = _endY - _startY;
    float error = -1.0;
    assert(deltaX != 0);
    float deltaErr = std::abs(deltaY / deltaX);
    int y = _startY;
    for (unsigned int x = _startX; x < _endX; ++x)
    {
        image.setPixel(x, y, _r, _g, _b);
        error += deltaErr;
        if (error >= 0.0)
        {
            ++y;
            error -= 1.0;
         }
    }

    image.save("picture-line.png");
    return;
}

/* Investigate the use of fmod to create repeating patterns
 *  such as a sphere
 */
void repeatingPatterns()
{

}
