add_executable(diffusetriangle diffusetriangle/main.cpp diffusetriangle/diffusetriangleapp.cpp)
include_directories(diffusetriangle "..")
target_link_libraries(diffusetriangle engine GL GLEW SDL2)

add_executable(texturedtriangle texturedtriangle/main.cpp)
include_directories(texturedtriangle "..")
target_link_libraries(texturedtriangle engine GL GLEW SDL2)

add_executable(cameratest cameratest/main.cpp)
include_directories(cameratest "..")
target_link_libraries(cameratest engine GL GLEW SDL2)

add_executable(objmesh objmesh/main.cpp)
include_directories(objmesh "..")
target_link_libraries(objmesh engine GL GLEW SDL2)

add_executable(lambert lambert/main.cpp)
include_directories(lambert "..")
target_link_libraries(lambert engine GL GLEW SDL2)

add_executable(luatest luatest/main.cpp)
include_directories(luatest "..")
target_link_libraries(luatest engine GL GLEW SDL2 luajit-5.1)
