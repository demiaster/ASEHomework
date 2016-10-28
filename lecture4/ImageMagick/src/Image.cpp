#include "Image.h"

void Image::setPixel(std::size_t _x,
              std::size_t _y,
              unsigned char _r,
              unsigned char _g,
              unsigned char _b)
{
    /*unsigned char colorComponents[m_pixelDepth];

    for (auto i : colorComponents)
    {
        int index = getIndex(_x, _y, i);
    }*/

    m_data[getIndex(_x, _y, 0)] = _r;
    m_data[getIndex(_x, _y, 1)] = _g;
    m_data[getIndex(_x, _y, 2)] = _b;

    return;
}

bool Image::save(std::string _fname) {}

void Image::clearScreen(unsigned char _r,
                 unsigned char _g,
                 unsigned char _b)
{
    for( int i = 0; i < m_width; ++i)
    {
        for( int j = 0; j < m_height; ++j)
        {
            setPixel(i, j, _r, _g, _b);
        }
    }

    return;
}

