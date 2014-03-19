add_library(engine 
	camera.cpp
        cameratransform.cpp
	fragmentshader.cpp
        mesh.cpp
	shader.cpp
	shaderprogram.cpp
	texture.cpp
	transform.cpp
        vertex.cpp
	vertexshader.cpp)

target_link_libraries(engine GL GLEW)
