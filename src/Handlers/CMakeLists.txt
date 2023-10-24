add_library(handlers
        Types/StringQuoteHandler.cpp
        Types/CharacterQuoteHandler.cpp
        Types/ShortCommentHandler.cpp
        Types/LongCommentHandler.cpp
        IHandler.cpp
)

target_include_directories(constructions PUBLIC include ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(handlers PUBLIC constructions scope_state)