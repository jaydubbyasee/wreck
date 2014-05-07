#ifndef __WRECK_ENGINE_BASICAPPLICATION_H
#define __WRECK_ENGINE_BASICAPPLICATION_H

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
    virtual void load_resources();

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

    bool running;

private:
    virtual void initGLEW();
    virtual void initSDL();
};

}

#endif // __WRECK_ENGINE_BASICAPPLICATION_H
