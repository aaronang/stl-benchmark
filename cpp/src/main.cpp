#include <iostream>
#include "benchmark/benchmark.h"
#include "parse_stl.h"

static void ParseStl(benchmark::State& state) {
    std::string stl = "nist.stl";
    for (auto _ : state) {
        stl::parse_stl(stl);
    }
}

BENCHMARK(ParseStl);

BENCHMARK_MAIN();
