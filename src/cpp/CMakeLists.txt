file(GLOB_RECURSE RS_SOURCES
        "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp"
)

add_executable(${PROJECT_NAME} main.cpp
        ${RS_SOURCES}

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
        "${CMAKE_CURRENT_SOURCE_DIR}/util/logger/include/interface"
        "${CMAKE_CURRENT_SOURCE_DIR}/util/logger/include"
        "${CMAKE_CURRENT_SOURCE_DIR}/util/logger/impl"
        "${CMAKE_CURRENT_SOURCE_DIR}/util/logger"
        "${CMAKE_CURRENT_SOURCE_DIR}/util/thread/include"
        "${CMAKE_CURRENT_SOURCE_DIR}/util/thread"
        "${CMAKE_CURRENT_SOURCE_DIR}/asset/include/interface/"
        "${CMAKE_CURRENT_SOURCE_DIR}/asset/include/"
        "${CMAKE_CURRENT_SOURCE_DIR}/asset/loader"
        "${CMAKE_CURRENT_SOURCE_DIR}/asset"
        "${CMAKE_CURRENT_SOURCE_DIR}/rs/include/"
)