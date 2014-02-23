add_library(engine 
				fragmentshader.cpp
				shader.cpp
				shaderprogram.cpp
				texture.cpp
				vertexshader.cpp)

target_link_libraries(engine GL GLEW)