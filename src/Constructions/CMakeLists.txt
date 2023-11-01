add_library(constructions ConstructionsStreamExtractor.cpp)

find_package(nlohmann_json CONFIG REQUIRED)
find_package(Boost REQUIRED)

target_include_directories(constructions PUBLIC include ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(constructions PUBLIC nlohmann_json::nlohmann_json Boost::boost tokenizers handlers)