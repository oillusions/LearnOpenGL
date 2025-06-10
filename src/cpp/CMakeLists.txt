file(GLOB_RECURSE RS_SOURCES
        "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp"
)

add_executable(${PROJECT_NAME} main.cpp
        ${RS_SOURCES}
        rs/include/render_system.h
        rs/src/render_system.cpp

)

configure_file(${PROJECT_SOURCE_DIR}/project_config.h.in "${PROJECT_SOURCE_DIR}/src/cpp/project_config.h")


target_link_libraries(${PROJECT_NAME} PRIVATE
        glfw
        glad
        glm
        stb
        ${WIN_LIBS}
)

target_include_directories(${PROJECT_NAME} PRIVATE
        ${CMAKE_SOURCE_DIR}/include
        "${CMAKE_CURRENT_SOURCE_DIR}/"
        "${CMAKE_CURRENT_SOURCE_DIR}/config/include"
        "${CMAKE_CURRENT_SOURCE_DIR}/rs/include"
)