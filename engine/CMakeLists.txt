add_library(engine 
	camera.cpp
        cameratransform.cpp
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

target_link_libraries(engine GL GLEW)
