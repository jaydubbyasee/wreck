#include "config.h"
#include <iostream>

namespace wreck
{

Config::Config()
{
    L = nullptr;
}

Config::~Config()
{
    if(L) { lua_close(L); }
}

bool Config::load(std::string filename)
{
    L = luaL_newstate();
    if(L == nullptr)
    {
        std::cout << "Could not open file: " << filename << std::endl;
    }

    if(luaL_dofile(L, filename.c_str()) != 0)
    {
        std::cout << "Syntax error in lua file" << std::endl;
    }
}

int Config::getVariableAsInt(std::string variable)
{
    return static_cast<int>(getVariableAsDouble(variable));
}

double Config::getVariableAsDouble(std::string variable)
{
    double retVal = 0;
    lua_getglobal(L, variable.c_str());

    if(lua_isnumber(L, -1))
    {
        retVal = lua_tonumber(L, -1);
    }

    lua_pop(L, 1);
    return retVal;
}

float Config::getVariableAsFloat(std::string variable)
{
    return static_cast<float>(getVariableAsDouble(variable));
}

std::string Config::getVariableAsString(std::string variable)
{
    std::string str = "";
    lua_getglobal(L, variable.c_str());

    if(lua_isstring(L, -1))
    {
        const char* luastr = lua_tostring(L, -1);
        str = std::string(luastr);
    }

    lua_pop(L, -1);
    return str;
}

/*

int Config::getVariableAsInt(std::string variable)
{
    std::istringstream iss(variable);
    std::string token;
    int depth = 0;
    while(std::getline(iss, token, '.'))
    {
        if(depth == 0)
        {
            // Get table
        }
        else
        {

        }
    }
}

*/

}
