add_library(engine shader.cpp
			       shaderprogram.cpp)

target_link_libraries(engine GL GLEW)