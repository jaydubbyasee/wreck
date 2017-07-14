include_directories(
	${GLEW_INCLUDE_DIRECTORY}
	${SDL2_INCLUDE_DIRECTORY}
	${DEPENDENCIES_INCLUDE_DIRECTORY})

add_library(engine
    basicapplication.cpp
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

target_link_libraries(engine
	gl
	${GLEW_LIBRARIES}
	${SDL2_LIBRARIES})
