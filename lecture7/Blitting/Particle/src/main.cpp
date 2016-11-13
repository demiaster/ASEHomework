#include <cstdlib>
#include <cstring>
#include <chrono>
#include <thread>
#include <array>
#include <iostream>
#include <string>
#include <random>
#include "Framebuffer.h"
#include "Image.h"
#include "Vec2.h"
#include "Emitter.h"
int main()
{




    std::unique_ptr<frm::Framebuffer> framebuffer( new frm::Framebuffer());
    size_t width=1024;
    size_t height=720;
    framebuffer->init(width, height, NULL);

    Image image(width,height);
    image.setBackground(255,255,255);

    framebuffer->bind();
    framebuffer->poll();

    framebuffer->title("Particle");
    Vec2<int> pos(width/2,height/2);
    Vec2<int> dir(1,1);
    Emitter p(pos,2000000);
    while(!framebuffer->shouldClose())
    {
      image.setBackground(255,255,255);
      p.update();
      p.draw(image);
      framebuffer->image(image.get(),width,height);
      framebuffer->draw();
      framebuffer->poll();

    }


  return EXIT_SUCCESS;
}







