add_library(constructions ConstructionsStreamExtractor.cpp)

target_include_directories(constructions PUBLIC include ${CMAKE_CURRENT_SOURCE_DIR})

find_package(nlohmann_json CONFIG REQUIRED)
target_link_libraries(constructions PUBLIC nlohmann_json)