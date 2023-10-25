add_library(languages LanguageHandlersSelector.cpp
        Language.h)

target_link_libraries(languages PUBLIC handlers)