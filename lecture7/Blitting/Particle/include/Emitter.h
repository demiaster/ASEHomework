#ifndef EMITTER_H_
#define EMITTER_H_

#include "Particle.h"
#include "Image.h"
#include <vector>
#include <memory>
class Emitter
{
  public :
    Emitter(Vec2<int> _pos, int _num);
    void update();
    void draw(Image &_i) const;
  private :
    std::vector <std::unique_ptr <Particle>> m_particles;
};



#endif
