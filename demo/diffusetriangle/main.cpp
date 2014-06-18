#include <iostream>
#include <GL/glew.h>
#include <SDL2/SDL.h>

#include "graphics/vertexshader.h"
#include "graphics/fragmentshader.h"
#include "graphics/shaderprogram.h"

using namespace wreck;

float vertexBuffer[] = {
    0.0f,0.0f,0.0f,
    1.0f,0.0f,0.0f,
    1.0f,1.0f,0.0f
};

int main(int argc, char** argv)
{
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
        std::cout << "SDL failed to initialize" << std::endl;
        return -1;
    }

    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);

    SDL_Window* window = SDL_CreateWindow("Demo: Diffuse Triangle",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        800, 600,
        SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);

    if(NULL == window)
    {
        std::cout << "Failed to create window" << std::endl;
        return -1;
    }

    SDL_GLContext ctx = SDL_GL_CreateContext(window);

    glewExperimental = GL_TRUE;
    if(GLEW_OK != glewInit())
    {
        std::cout << "GLEW failed to initialize" << std::endl;
        return -1;
    }

    GLint err = GL_NO_ERROR;
    do
    {
        err = glGetError();
        std::cout << err << std::endl;
    }
    while(err != GL_NO_ERROR);

    GLuint vao, vbo;
    glGenVertexArrays(1, &vao);
    glGenBuffers(1, &vbo);

    // Describe the vertex layout
    glBindVertexArray(vao);

    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertexBuffer), vertexBuffer, GL_STATIC_DRAW);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

    VertexShader vs;
    FragmentShader fs;
    ShaderProgram shaderProg;

    if(!vs.load("assets/diffuse.vs")) std::cout << "Vertex Shader error." << std::endl;
    if(!fs.load("assets/diffuse.fs")) std::cout << "Fragment shader error." << std::endl;

    std::cout << "Linking..." << std::endl;
    shaderProg.setVertexShader(&vs);
    shaderProg.setFragmentShader(&fs);
    shaderProg.link();

    do
    {
        err = glGetError();
        std::cout << err << std::endl;
    }
    while(err != GL_NO_ERROR);

    glm::mat4 mvp(1.0f);
    glm::vec4 diffuse(0.0f, 1.0f, 1.0f, 1.0f); // Green
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Black

    bool running = true;
    while(running)
    {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        SDL_Event event;
        while(SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            case SDL_KEYDOWN:
                break;
            case SDL_KEYUP:
                // if escape is pressed, quit
                if (event.key.keysym.sym == SDLK_ESCAPE)
                    running = false; // set status to 1 to exit main loop
                break;
            case SDL_QUIT:
                running = false;
                break;
            }
        }

        // Begin drawing
        shaderProg.begin();
            shaderProg.setUniformValue(0, mvp);
            shaderProg.setUniformValue(1, diffuse);
            glDrawArrays(GL_TRIANGLES, 0, 3);
        shaderProg.end();

        SDL_GL_SwapWindow(window);
    }

    SDL_GL_DeleteContext(ctx);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
