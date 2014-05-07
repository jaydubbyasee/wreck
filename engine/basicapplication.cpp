#include "basicapplication.h"
#include <SDL2/SDL.h>

namespace wreck
{

BasicApplication::BasicApplication()
{
}

void BasicApplication::run()
{
    Uint32 ticks = 0;
    Uint32 ticksSinceLastFrame = 0;

    while(running)
    {
        ticksSinceLastFrame = SDL_TICKS_PASSED(SDL_GetTicks(), ticks);
        ticks = SDL_GetTicks();

        update(ticksSinceLastFrame);
        draw();
    }
}

void BasicApplication::init()
{
    // Init SDL2

    // Init GLEW
}

void BasicApplication::loadResources()
{

}

void BasicApplication::update(Uint32 ticks)
{

}

void BasicApplication::draw()
{

}

}
