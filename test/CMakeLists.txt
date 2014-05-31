add_executable(engine_unittest configtest.cpp)
include_directories(engine_unittest "..")
target_link_libraries(engine_unittest gtest gtest_main engine GL GLEW SDL2)
