#include "Image.h"
#include <cstdlib>
#include <iostream>

// random shits
#include <random>
#include <algorithm>
#include <sstream>

//line things
#include <cmath>
#define NDEBUG
#include <cassert>

constexpr int WIDTH = 1920;
constexpr int HEIGHT = 1080;
constexpr int DEPTH = 3;

void rnd(int);

void line(Image &image, const int _startX, const int _startY,
           const int _endX, const int _endY,
           const unsigned char _r, const unsigned char _g, const unsigned char _b);

void bhm_line(const Image& image, int x1,int y1,int x2,int y2,
              const unsigned char _r, const unsigned char _g, const unsigned char _b);

void rainbowWheel();

int main()
{
    std::cout<<"Need to write an Image Class\n";
    Image image(WIDTH, HEIGHT, DEPTH);
    image.clearScreen(67, 189, 242);
    image.save("picture.png");

    //for (int i = 0; i < 50; ++i)
    //    rnd(i);
    // Create a video with: ffmpeg -i picture-$DISTRIBUTION-%d.png output.gif

    //line(100, 100, 800, 800, 255, 0, 0);

    rainbowWheel();

    return EXIT_SUCCESS;
}

#define NORMAL 1
#ifdef NORMAL
#define DISTRIBUTION std::normal_distribution<double> distribution(128,128)
#define NORMALIZE (unsigned int)distribution(generator) % 255
#define DSTRING "normal"
#elif GAMMA
#define DISTRIBUTION std::gamma_distribution<char> distribution(2.0,2.0)
#define DSTRING "gamma"
#endif //GAMMA

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

/* Breseham's line algorithm
 *  function line(x0, y0, x1, y1)
 *    real deltax := x1 - x0
 *    real deltay := y1 - y0
 *    real error := -1.0
 *    real deltaerr := abs(deltay / deltax)
 *
 *    // Assume deltax != 0 (line is not vertical),
 *    // note that this division needs to be done
 *    //in a way that preserves the fractional part
 *
 *    int y := y0
 *    for x from x0 to x1-1
 *        plot(x,y)
 *        error := error + deltaerr
 *        if error ≥ 0.0 then
 *            y := y + 1
 *            error := error - 1.0
 */

//line apparently does not work properly
void line(Image& image,
          const int _startX, const int _startY,
           const int _endX, const int _endY,
           const unsigned char _r, const unsigned char _g, const unsigned char _b)
{
    //check input validity
    assert(0 < _startX && _startX < WIDTH);
    assert(0 < _endX && _endX < WIDTH);
    assert(0 < _startY && _startY < HEIGHT);
    assert(0 < _endY && _endY < HEIGHT);

    float deltaX = _endX - _startX;
    float deltaY = _endY - _startY;
    float error = -1.0;

    //this algorithm only works for deltaX not zero
    assert(deltaX != 0);
    float deltaErr = std::fabs(deltaY / deltaX);
    int y = _startY;
    for (int x = _startX; x < _endX; ++x)
    {
        image.setPixel(x, y, _r, _g, _b);
        error += deltaErr;
        if (error >= 0.0)
        {
            ++y;
            error -= 1.0;
         }
    }

    return;
}

//same algorithm from
//http://www.etechplanet.com/codesnippets/computer-graphics-draw-a-line-using-bresenham-algorithm.aspx
void bhm_line(Image& image,
              int x1, int y1, int x2, int y2,
              const unsigned char _r,
              const unsigned char _g,
              const unsigned char _b)
{
     int x, y;
     int dx, dy;
     int dx1, dy1;
     int px, py;
     int xe, ye;

     dx = x2 - x1;
     dy = y2 - y1;
     dx1 = fabs(dx);
     dy1 = fabs(dy);
     px = 2 * dy1 - dx1;
     py = 2 * dx1 - dy1;

     if (dy1 <= dx1)
     {

         if (dx >= 0)
          {
               x = x1;
               y = y1;
               xe = x2;
          }
          else
          {
               x = x2;
               y = y2;
               xe = x1;
          }
          image.setPixel(x, y, _r, _g, _b);

          for (int i=0; x < xe; ++i)
          {
               ++x;
               if (px < 0)
               {
                    px += 2 * dy1;
               }
               else
               {
                    if ((dx < 0 && dy < 0) || (dx > 0 && dy > 0))
                    {
                        ++y;
                    }
                    else
                    {
                        --y;
                    }
                    px += 2 * (dy1 - dx1);
               }
               image.setPixel(x, y, _r, _g, _b);
          }
     }
     else
     {
          if(dy >= 0)
          {
               x = x1;
               y = y1;
               ye = y2;
          }
          else
          {
               x = x2;
               y = y2;
               ye = y1;
          }
          image.setPixel(x, y, _r, _g, _b);

          for (int i = 0; y < ye; ++i)
          {
               ++y;
               if(py <= 0)
               {
                    py += 2 * dx1;
               }
               else
               {
                    if ((dx < 0 && dy < 0) || (dx > 0 && dy > 0))
                    {
                        ++x;
                    }
                    else
                    {
                        --x;
                    }
                    py += 2 * (dx1 - dy1);
               }
               image.setPixel(x, y, _r, _g, _b);
          }
     }
}

typedef struct Point_s
{
    unsigned int x;
    unsigned int y;
} Point;

#define POW(X) ((X)*(X))

class LineYielder
{
public:
    inline LineYielder(const Point& _pinit, const Point& _pend) :
        m_center(_pinit),
        m_radius(std::sqrt(POW(_pend.x - _pinit.x) + POW(_pend.y - _pinit.y))),
        m_angle(std::atan2(_pend.y - _pinit.y, _pend.x - _pinit.x)) {;}

    inline Point nextLine(const float _delta)
    {
        m_angle = m_angle + _delta;
        int x = m_radius * std::cos(m_angle) + m_center.x;
        int y = m_radius * std::sin(m_angle) + m_center.y;
        return Point{x, y};
    }

private:
    const Point& m_center;
    float m_radius;
    float m_angle;
};

void rainbowWheel()
{
    Image image(WIDTH, HEIGHT);

    //cleaning background
    image.clearScreen(0, 0, 0);

    Point center = Point{960, 540};

    LineYielder yielder(center, Point{1060, 540});

    for (int i = 0; i < 100000; ++i)
    {
        Point next = yielder.nextLine(0.1);
        bhm_line(image, center.x, center.y, next.x, next.y, 255, 0, 0);
    }
    image.save("picture-redlines.png");
}

/* Investigate the use of fmod to create repeating patterns
 *  such as a sphere
 */
void repeatingPatterns()
{

}
