cmake_minimum_required(VERSION 3.20)
project(myproject)

set(LIB "printhw")
add_executable(${PROJECT_NAME} main.cpp)

target_link_libraries(${PROJECT_NAME} ${LIB})

add_subdirectory(lib)

add_custom_target(
    run_program
    COMMAND ${PROJECT_NAME}
)