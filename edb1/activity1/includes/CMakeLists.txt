add_library(${ACTLIB} lib.cpp)

target_include_directories( 
    ${ACTLIB} 
    PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR} 
)