cmake_minimum_required(VERSION 3.31)
project(LearnOpenGL VERSION 1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)

set(WIN_LIBS opengl32 gdi32)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_subdirectory(libs/glfw-3.4)


add_library(glad STATIC include/glad/src/glad.c)
add_library(stb STATIC include/stb/src/stb_image.cpp)
add_library(glm INTERFACE)
target_include_directories(glad PUBLIC include/glad/include include/glad/include/KHR)
target_include_directories(stb PUBLIC include/stb/include)
target_include_directories(glm INTERFACE include/glm)

set(VERSION 1.0.0)

add_subdirectory(src/cpp)
