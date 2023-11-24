add_library(tokenizers SHARED Tokenizer.cpp)

target_include_directories(tokenizers PUBLIC include ${CMAKE_CURRENT_SOURCE_DIR})

find_package(nlohmann_json CONFIG REQUIRED)
target_link_libraries(tokenizers PUBLIC nlohmann_json::nlohmann_json)