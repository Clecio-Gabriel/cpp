cmake_minimum_required(VERSION 3.18)
project ( Filter VERSION 1.0 LANGUAGES CXX )

set(CMAKE_EXPORT_COMPILE_COMMANDS 1)

# #=== Test target ===
set( TEST_LIB "tm" )
add_subdirectory(tm) # This will ask this lib to be build
set ( TEST_DRIVER "all_tests")
add_subdirectory(tests) # This will ask the tests to be generated

# optional target, if you with to build & run tests with a single command,
# as in `cmake --build build --target run_tests`
add_custom_target(
    run_tests
    COMMAND ${TEST_DRIVER} 2> /dev/null 
    DEPENDS ${LIB_NAME}
)
