add_library(analyzers
        JavaAnalyzer.cpp
        JavascriptAnalyzer.cpp
        CSharpAnalyzer.cpp
        GoAnalyzer.cpp
        GroovyAnalyzer.cpp
        JsonAnalyzer.cpp
        KotlinAnalyzer.cpp
        ObjectiveCAnalyzer.cpp
        ScalaAnalyzer.cpp
        SwiftAnalyzer.cpp
)

target_include_directories(analyzers PUBLIC include ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(analyzers PUBLIC handlers analyzer_types)