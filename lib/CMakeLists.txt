add_library(scope_lib ScopeAnalyzer.cpp)
target_include_directories(scope_lib PUBLIC include ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(scope_lib PUBLIC constructions)