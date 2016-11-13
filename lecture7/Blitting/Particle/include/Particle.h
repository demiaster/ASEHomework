#ifndef PARTICLE_H_
#define PARTICLE_H_

#include "Vec2.h"
#include "Image.h"
class Particle
{
  public :
    Particle(Vec2 <int> _pos);
    void update();
    void draw(Image &_i) const;
  private :
    Vec2<int> m_pos;
    Vec2<int> m_emitterPos;
    Vec2<int> m_dir;
    int m_life;
    int m_maxLife;
    unsigned char m_r;
    unsigned char m_g;
    unsigned char m_b;
};


#endif
