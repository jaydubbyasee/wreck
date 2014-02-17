add_library(engine 
				fragmentshader.cpp
				shader.cpp
				shaderprogram.cpp
				vertexshader.cpp)

target_link_libraries(engine GL GLEW)