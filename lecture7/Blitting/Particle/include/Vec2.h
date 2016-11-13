#ifndef VEC2_H_
#define VEC2_H_
#include <ostream>

template <typename T>
class Vec2
{
  public :
    Vec2() : m_x(0), m_y(0){}
    Vec2(T _x, T _y) : m_x(_x), m_y(_y){}
    friend std::ostream &operator<<(std::ostream &_o, const Vec2<T> _s)
    {
      return _o<<'['<<_s.m_x<<','<<_s.m_y<<"]\n";
    }

    Vec2 operator +(const Vec2 & _v) const ;

    void operator +=(const Vec2<T> &_v)
    {
      m_x+=_v.m_x;
      m_y+=_v.m_y;
    }

    void set(T _x, T _y)
    {
      m_x=_x;
      m_y=_y;
    }

    T m_x;
    T m_y;
};



template <typename T>
Vec2<T> Vec2<T>::operator+(const Vec2<T> &_v ) const
{
  return Vec2<T>(m_x + _v.m_x , m_y + _v.m_y);
}



#endif
