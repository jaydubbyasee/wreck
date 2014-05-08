#include "basicapplication.h"
#include <iostream>
#include <GL/glew.h>
#include <SDL2/SDL.h>

namespace wreck
{

BasicApplication::BasicApplication()
{
    windowTitle = "Basic Application";
    width = 800;
    height = 600;
}

void BasicApplication::run()
{
    Uint32 ticks = 0;
    Uint32 ticksSinceLastFrame = 0;

    init();
    loadResources();

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
    initSDL();
    initGLEW();
}

void BasicApplication::loadResources()
{
    // No-op
}

void BasicApplication::update(Uint32 ticks)
{
    // No-op
}

void BasicApplication::draw()
{
    // No-op
}

bool BasicApplication::initGLEW()
{
    glewExperimental = GL_TRUE;
    if(GLEW_OK != glewInit())
    {
        std::cout << "GLEW failed to initialize" << std::endl;
        return false;
    }

    GLint err = GL_NO_ERROR;
    do
    {
        err = glGetError();
        std::cout << err << std::endl;
    }
    while(err != GL_NO_ERROR);

    return true;
}

bool BasicApplication::initSDL()
{
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
        std::cout << "SDL failed to initialize" << std::endl;
        return false;
    }

    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 4);

    // Create window
    window = SDL_CreateWindow(windowTitle.c_str(),
                              SDL_WINDOWPOS_CENTERED,
                              SDL_WINDOWPOS_CENTERED,
                              width, height,
                              SDL_WINDOW_OPENGL | SDL_WINDOW_FULLSCREEN);

    if(NULL == window)
    {
        std::cout << "Failed to create window" << std::endl;
        return false;
    }

    glContext = SDL_GL_CreateContext(window);
    SDL_ShowCursor(0);

    return true;
}

}
