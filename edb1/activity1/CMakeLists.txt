cmake_minimum_required(VERSION 3.31)
project(EDB1_ACTIVITY VERSION 1.0 LANGUAGES CXX)

set(ACTLIB activity_lib)
add_subdirectory(includes)

set(TEST_EXECUTABLE tester)
add_subdirectory(tests)

set(ANSWERS_C answersl)
add_library(${ANSWERS_C} answers.cpp)

target_link_libraries(
    ${ANSWERS_C}
    PUBLIC
    ${ACTLIB}
)

target_link_libraries(
    ${TEST_EXECUTABLE}
    PRIVATE
    ${ANSWERS_C}
)

add_custom_target(
    run_test
    COMMAND ${TEST_EXECUTABLE}
)