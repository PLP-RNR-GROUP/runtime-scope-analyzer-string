add_library(analyzer_types
        BraceAnalyzer.cpp
        IndentationAnalyzer.cpp
        BaseAnalyzer.cpp
)

target_include_directories(analyzer_types PUBLIC include ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(analyzer_types PUBLIC constructions_stream_extractor handlers_map tokenizers)