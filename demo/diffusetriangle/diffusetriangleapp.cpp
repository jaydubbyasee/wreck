#include "diffusetriangleapp.h"
#include <GL/glew.h>
#include <SDL2/SDL.h>

DiffuseTriangleApp::DiffuseTriangleApp()
{
}

void DiffuseTriangleApp::loadResources()
{
    // Load stuff
    // Load shaders from file

    wreck::BasicApplication::loadResources();
}

void DiffuseTriangleApp::update(Uint32 ticks)
{
    // Update stuff

    wreck::BasicApplication::update(ticks);
}

void DiffuseTriangleApp::draw()
{   
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BITS | GL_STENCIL_BITS);

    // Draw stuff

    SDL_GL_SwapWindow(window);
}
