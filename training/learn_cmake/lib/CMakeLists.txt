add_library(${LIB} lib.cpp)

target_include_directories(
    ${LIB}
    INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}
)