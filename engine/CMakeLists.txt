add_library(engine SHARED
    basicapplication.cpp
    camera.cpp
    cameratransform.cpp
    config.cpp
    entity.cpp
    light.cpp)

include_directories(engine "..")
target_link_libraries(engine core graphics GL GLEW luajit-5.1)
