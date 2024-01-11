cmake_minimum_required(VERSION 3.26)
project(runtime)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

add_subdirectory(src)
add_subdirectory(lib)
add_subdirectory(benchmarks)

add_executable(runtime main.cpp)

find_package(nlohmann_json CONFIG REQUIRED)
target_link_libraries(runtime PUBLIC scope_lib nlohmann_json)