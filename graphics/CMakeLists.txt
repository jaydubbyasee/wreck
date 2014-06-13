add_library(graphics SHARED
    fragmentshader.cpp
    mesh.cpp
    shader.cpp
    shaderprogram.cpp
    texture.cpp
    vertex.cpp
    vertexshader.cpp
    wavefrontmeshfactory.cpp)

include_directories(engine "..")
target_link_libraries(graphics GL GLEW)
