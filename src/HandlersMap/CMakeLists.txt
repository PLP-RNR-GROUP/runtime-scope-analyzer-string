add_library(handlers_map SHARED HandlersMap.cpp)

target_include_directories(handlers_map PUBLIC include ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(handlers_map PUBLIC handlers)