add_library(engine 
	camera.cpp
        cameratransform.cpp
	fragmentshader.cpp
	shader.cpp
	shaderprogram.cpp
	texture.cpp
	transform.cpp
	vertexshader.cpp)

target_link_libraries(engine GL GLEW)
