add_library(scope_lib SHARED ScopeAnalyzer.cpp)

target_include_directories(scope_lib PUBLIC include ${CMAKE_CURRENT_SOURCE_DIR})

find_package(Boost REQUIRED)
target_link_libraries(scope_lib PUBLIC constructions handlers scope_state languages Boost::boost)