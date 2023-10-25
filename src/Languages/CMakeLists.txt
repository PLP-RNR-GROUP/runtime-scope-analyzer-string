add_library(languages LanguageHandlersSelector.cpp
        include/Languages/Language.h)

target_include_directories(languages PUBLIC include ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(languages PUBLIC handlers)