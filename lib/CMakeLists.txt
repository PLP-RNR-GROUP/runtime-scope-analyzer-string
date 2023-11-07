add_library(scope_lib SHARED
        ScopeAnalyzer.cpp
        Analyzers/BraceAnalyzer.cpp
        Analyzers/IndentationAnalyzer.cpp
)

target_include_directories(scope_lib PUBLIC include ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(scope_lib PUBLIC constructions handlers languages scope_analyzer_state)