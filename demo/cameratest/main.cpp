#include <iostream>
#include <GL/glew.h>
#include <SDL2/SDL.h>
#include <glm/glm.hpp>
#include "engine/transform.h"
#include "engine/camera.h"
#include "engine/vertexshader.h"
#include "engine/fragmentshader.h"
#include "engine/shaderprogram.h"
#include "engine/texture.h"

using namespace wreck;

const int width = 1920.0f;
const int height = 1080.0f;

float vertexBuffer[] =
{
	0.0f,0.0f,0.0f,
	1.0f,0.0f,0.0f,
	1.0f,1.0f,0.0f
};

float uvBuffer[] =
{
	0.0f,0.0f,
	1.0f,0.0f,
	1.0f,1.0f
};

bool initSDL(SDL_Window** window, SDL_GLContext* ctx)
{
	if(SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		std::cout << "SDL failed to initialize" << std::endl;
		return false;
	}

	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);

    *window = SDL_CreateWindow("Demo: Camera Test",
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
        width, height,
        SDL_WINDOW_OPENGL | SDL_WINDOW_FULLSCREEN);

	if(NULL == window)
	{
		std::cout << "Failed to create window" << std::endl;
		return false;
	}

	*ctx = SDL_GL_CreateContext(*window);

    SDL_WarpMouseInWindow(*window, width/2, height/2);
    SDL_ShowCursor(0);

	return true;
}

bool initGLEW()
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

void createMesh(GLuint& vao)
{
    GLuint vbo;
    GLuint uvbo;

    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);
    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertexBuffer), vertexBuffer, GL_STATIC_DRAW);

    // Note: Remember that the glVertexAttribPointer should not be called until after
    // a vertex buffer object has been bound. Otherwise, you may encounter a segfault.
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

    glGenBuffers(1, &uvbo);
    glBindBuffer(GL_ARRAY_BUFFER, uvbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(uvBuffer), uvBuffer, GL_STATIC_DRAW);

    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, 0);

    // In practical situations, it may be useful to store Textures in a collection of
    // some sort so they may be reused for additional mesh instances.
    Texture tex;
    tex.load("../../wreck/assets/uvpattern.dds");
    tex.use();
}

void keyboardCameraControl(SDL_Event& evt, Camera& camera, Uint32 ticksSinceLastFrame)
{
    glm::vec3 f = camera.getTransform()->forward();
    glm::vec3 r = camera.getTransform()->right();

    switch(evt.key.keysym.sym)
    {
    case SDLK_w:
        camera.getTransform()->translate(f.x, f.y, f.z);
        break;
    case SDLK_a:
        camera.getTransform()->translate(-r.x, -r.y, -r.z);
        break;
    case SDLK_s:
        camera.getTransform()->translate(-f.x, -f.y, -f.z);
        break;
    case SDLK_d:
        camera.getTransform()->translate(r.x, r.y, r.z);
        break;
    }
}

void mouseCameraControl(SDL_Event& evt, SDL_Window* window, Camera& camera, Uint32 ticksSinceLastFrame)
{
    float radiansPerSecond = 0.1f;
    float x = -evt.motion.xrel * (0.001f*ticksSinceLastFrame)*radiansPerSecond;
    float y = -evt.motion.yrel * (0.001f*ticksSinceLastFrame)*radiansPerSecond;

    SDL_WarpMouseInWindow(window, width/2, height/2);
    camera.getTransform()->rotate(y, x, 0.0f);
}

int main(int argc, char** argv)
{
	SDL_Window* window;
	SDL_GLContext ctx;
    GLuint vao;

	if(!initSDL(&window, &ctx) || !initGLEW())
	{
		return false;
	}

    // Create camera
    Camera camera(glm::radians(60.0f),
                  static_cast<float>(width)/static_cast<float>(height),
                  0.1f,
                  1000.0f);
    camera.getTransform()->setPosition(0.0f,0.0f,5.0f);
    createMesh(vao);

	VertexShader vs;
	FragmentShader fs;
	ShaderProgram shaderProg;

    if(!vs.load("../../wreck/assets/textured_diffuse.vs")) std::cout << "Vertex Shader error." << std::endl;
    if(!fs.load("../../wreck/assets/textured_diffuse.fs")) std::cout << "Fragment shader error." << std::endl;

	std::cout << "Linking..." << std::endl;
	shaderProg.setVertexShader(&vs);
	shaderProg.setFragmentShader(&fs);
	shaderProg.link();

	glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Black

    glm::mat4 v = camera.getViewMatrix();
    glm::mat4 p = camera.getProjectionMatrix();
    Uint32 ticks = SDL_GetTicks();
	bool running = true;
	while(running)
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		SDL_Event event;
		while(SDL_PollEvent(&event))
		{
            Uint32 elapsed = SDL_GetTicks()-ticks;
            ticks = SDL_GetTicks();

			switch (event.type)
            {
            case SDL_KEYDOWN:
                keyboardCameraControl(event, camera, elapsed);
                break;
            case SDL_KEYUP:
                // if escape is pressed, quit
                if (event.key.keysym.sym == SDLK_ESCAPE)
                    running = false; // set status to 1 to exit main loop
                break;
            case SDL_MOUSEMOTION:
                mouseCameraControl(event, window, camera, elapsed);
                break;
            case SDL_QUIT:
                running = false;
                break;
            }
		}

		// Begin drawing
		shaderProg.begin();
            glm::mat4 mvp = p*camera.getViewMatrix();
            shaderProg.setUniformValue(0, mvp);
			glDrawArrays(GL_TRIANGLES, 0, 3);
		shaderProg.end();

		SDL_GL_SwapWindow(window);
	}

	SDL_GL_DeleteContext(ctx);
    SDL_DestroyWindow(window);
    SDL_Quit();

	return 0;
}
