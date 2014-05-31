#ifndef CONFIG_H
#define CONFIG_H

#include <string>
#include <luajit-2.0/lua.hpp>

namespace wreck
{

class Config
{
public:
    Config();
    ~Config();

    bool        load(std::string filename);
    int         getVariableAsInt(std::string variable);
    double      getVariableAsDouble(std::string variable);
    float       getVariableAsFloat(std::string variable);
    bool        getVariableAsBool(std::string variable);
    std::string getVariableAsString(std::string variable);

private:
    lua_State *L;
};

}

#endif // CONFIG_H
