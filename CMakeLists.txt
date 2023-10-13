cmake_minimum_required(VERSION 3.26)
project(runtime)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(src)
add_subdirectory(lib)

add_executable(runtime main.cpp)

find_package(nlohmann_json CONFIG REQUIRED)
target_link_libraries(runtime PUBLIC scope_lib nlohmann_json)