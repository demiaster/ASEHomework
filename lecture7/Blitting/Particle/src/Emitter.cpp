#include "Emitter.h"


Emitter::Emitter(Vec2<int> _pos, int _num)
{
  for(size_t i=0; i<_num; ++i)
    m_particles.emplace_back(new Particle(_pos));
}

void Emitter::update()
{
  for(auto &p : m_particles)
    p->update();
}

void Emitter::draw(Image &_i) const
{
  for(auto &p : m_particles)
    p->draw(_i);
}

