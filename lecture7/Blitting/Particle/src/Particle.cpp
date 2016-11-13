#include "Particle.h"
#include <random>

static std::mt19937 gen;

Particle::Particle(Vec2 <int> _pos)
{
  std::uniform_int_distribution<int> randDir(-5,5);
  std::uniform_int_distribution<int> randLife(3,50);

  m_emitterPos=_pos;
  m_pos=_pos;
  m_dir.set(randDir(gen),randDir(gen));
  m_life=0;
  m_maxLife=randLife(gen);

  std::uniform_int_distribution<int> randColour(0,255);
  m_r=randColour(gen);
  m_g=randColour(gen);
  m_b=randColour(gen);
}


void Particle::update()
{
  m_pos+=m_dir;
  if(++m_life > m_maxLife)
  {
    std::uniform_int_distribution<int> randLife(3,50);
    std::uniform_int_distribution<int> randDir(-10,10);
    m_dir.set(randDir(gen),randDir(gen));
    m_pos=m_emitterPos;
    m_life=0;
    m_maxLife=randLife(gen);
    std::uniform_int_distribution<int> randColour(0,255);
    m_r=randColour(gen);
    m_g=randColour(gen);
    m_b=randColour(gen);
  }

}

void Particle::draw(Image &_i) const
{
  _i.setPixel(m_pos.m_x, m_pos.m_y,m_r,m_g,m_b);
}
