add_library(languages INTERFACE)

target_include_directories(languages INTERFACE include ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(languages INTERFACE handlers analyzers analyzer_types)