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

int main()
{

    std::unique_ptr<frm::Framebuffer> framebuffer( new frm::Framebuffer());
    size_t width=1024;
    size_t height=720;
    framebuffer->init(width, height, NULL);

    Image image(width,height);
    image.setBackground(255,0,0);

    framebuffer->bind();
    framebuffer->poll();

    framebuffer->title("Red Line");

    while(!framebuffer->shouldClose())
    {
      for(size_t frame=0; frame<width; ++frame )
      {
          image.setBackground(255,255,255);
          for(size_t x=0; x<frame; ++x)
          {
            for(size_t y=80; y<120; ++y)
              image.setPixel(x,y,255,0,0);
                }
          framebuffer->poll();

          framebuffer->image(image.get(), width, height);
          framebuffer->draw();
          if(framebuffer->shouldClose())
            break;
      }
    }


  return EXIT_SUCCESS;
}
