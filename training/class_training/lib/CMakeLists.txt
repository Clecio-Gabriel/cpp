add_library(${CLASS_LIB} rect.cpp)

target_include_directories(
    ${CLASS_LIB}
    INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}
)