cmake_minimum_required(VERSION 3.18)
project(rectangleclass)

set(CLASS_LIB "recclass")
add_executable(${PROJECT_NAME} main.cpp)

target_link_libraries(
    ${PROJECT_NAME}
    ${CLASS_LIB}
)

add_subdirectory(lib)

add_custom_target(
    run_test
    COMMAND ${PROJECT_NAME}
)