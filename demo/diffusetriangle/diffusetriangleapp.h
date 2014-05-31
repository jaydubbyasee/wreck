#ifndef DIFFUSETRIANGLEAPP_H
#define DIFFUSETRIANGLEAPP_H

#include <engine/basicapplication.h>

class DiffuseTriangleApp : public wreck::BasicApplication
{
public:
    DiffuseTriangleApp();

    // BasicApplication interface
protected:
    void loadResources();
    void update(Uint32 ticks);
    void draw();
};

#endif // DIFFUSETRIANGLEAPP_H
