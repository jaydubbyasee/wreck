add_library(engine
    basicapplication.cpp
    camera.cpp
    cameratransform.cpp
    config.cpp
    entity.cpp
    fragmentshader.cpp
    light.cpp
    mesh.cpp
    shader.cpp
    shaderprogram.cpp
    texture.cpp
    transform.cpp
    vertex.cpp
    vertexshader.cpp
    wavefrontmeshfactory.cpp)

target_link_libraries(engine GL GLEW luajit-5.1)
