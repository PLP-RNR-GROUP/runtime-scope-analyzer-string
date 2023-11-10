add_library(analyzers JavaAnalyzer.cpp)

target_include_directories(analyzers PUBLIC include ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(analyzers PUBLIC handlers analyzer_types)