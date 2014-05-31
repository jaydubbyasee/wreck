#include <engine/basicapplication.h>
#include <engine/config.h>
#include <iostream>

using namespace wreck;

class LuaTest : public BasicApplication
{
    void loadResources()
    {
        Config config;
        config.load("assets/test.lua");

        std::string apple = config.getVariableAsString("apple");
        int one = config.getVariableAsInt("one");

        std::cout << apple << one << std::endl;

        this->running = false;
    }
};

int main(void)
{
    LuaTest luaTest;
    luaTest.run();
}
