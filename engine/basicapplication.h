#ifndef __WRECK_ENGINE_BASICAPPLICATION_H
#define __WRECK_ENGINE_BASICAPPLICATION_H

#include <SDL2/SDL.h>
#include <string>

namespace wreck
{

class BasicApplication
{
public:
    BasicApplication();

    void run();

protected:

    /**
     * @brief init Initializes all subsytems and libraries required prior
     * to start of application
     */
    virtual void init();

    /**
     * @brief loadResources Loads any resources/content that will be used
     * by the application.
     */
    virtual void loadResources();

    /**
     * @brief update This method is called once per frame update. Perform any
     * logic updates needed by the application.
     *
     * @param ticks The number of milliseconds since the last frame update
     */
    virtual void update(Uint32 ticks);

    /**
     * @brief draw This method draws a frame.
     */
    virtual void draw();

    bool            running;
    int             width;
    int             height;
    std::string     windowTitle;
    SDL_Window*     window;
    SDL_GLContext   glContext;

private:
    virtual bool initGLEW();
    virtual bool initSDL();
};

}

#endif // __WRECK_ENGINE_BASICAPPLICATION_H
