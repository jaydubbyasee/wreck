add_library(core
    file.cpp
    buffer.cpp
    logger.cpp
    matrix.cpp
    vector.cpp
    string.cpp
    transform.cpp)

target_link_libraries(core GL GLEW luajit-5.1)
