add_library(scope_lib Analyzer.cpp)

target_include_directories(scope_lib PUBLIC include ${CMAKE_CURRENT_SOURCE_DIR})

find_package(nlohmann_json CONFIG REQUIRED)
target_link_libraries(scope_lib PUBLIC nlohmann_json)