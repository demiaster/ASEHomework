#ifndef IMAGE_H_
#define IMAGE_H_
#include <cstddef>
#include <string>
#include <memory>

class Image
{
    public:
        inline Image(std::size_t _width,
                     std::size_t _height,
                     std::size_t _depth = 3) :
            m_width(_width),
            m_height(_height),
            m_pixelDepth(_depth),
            m_data(new unsigned char[m_width*m_height*m_pixelDepth]) {;}

        void setPixel(std::size_t _x,
                      std::size_t _y,
                      unsigned char _r,
                      unsigned char _g,
                      unsigned char _b);
        bool save(std::string _fname);

        void clearScreen(unsigned char _r,
                         unsigned char _g,
                         unsigned char _b);

        ~Image();



    private:
        std::unique_ptr<unsigned char> m_data;
        std::size_t m_height;
        std::size_t m_width;
        std::size_t m_pixelDepth;

        inline int getIndex (std::size_t _x,
                      std::size_t _y,
                      std::size_t _z) const
        {
            return (_x + m_width * _y) * m_pixelDepth + _z;
        }


};

#endif
