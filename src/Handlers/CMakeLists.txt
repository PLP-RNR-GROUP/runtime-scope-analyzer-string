add_library(handlers
        Types/StringQuoteHandler.cpp
        Types/CharacterQuoteHandler.cpp
        Types/ShortCommentHandler.cpp
        Types/LongCommentHandler.cpp
        Types/BraceHandler.cpp
        Types/BacktickHandler.cpp
        Types/ThreeDoubleQuoteHandler.cpp
        Types/ThreeQuoteHandler.cpp
        Types/DollarSlashyStringHandler.cpp
        Types/IndentationHandler.cpp

        IHandler.cpp
)

target_include_directories(handlers PUBLIC include ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(handlers PUBLIC constructions analyzer_types)
