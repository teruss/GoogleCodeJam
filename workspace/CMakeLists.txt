cmake_minimum_required(VERSION 2.8)

project(GoogleCodeJam)

include_directories("${PROJECT_SOURCE_DIR}" ../Catch/include)

file(GLOB TestSourceFiles test.cpp)

add_executable(exec main.cpp)
target_compile_features(exec PRIVATE cxx_auto_type cxx_long_long_type)
enable_testing()

add_executable(unit_test ${TestSourceFiles})
add_test(unit_test unit_test)
target_compile_features(unit_test PRIVATE cxx_auto_type)
