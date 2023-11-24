find_package(benchmark REQUIRED)

add_executable(benchmark_scope_analyzer scope_analyzer.cpp)
target_link_libraries(benchmark_scope_analyzer PRIVATE
        benchmark::benchmark_main
        scope_lib)

