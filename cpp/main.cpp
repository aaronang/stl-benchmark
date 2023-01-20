#include <cstdio>
#include <iostream>

#include "benchmark/benchmark.h"

struct point {
    float x;
    float y;
    float z;

    point() = default;
    point(float xp, float yp, float zp) : x(xp), y(yp), z(zp) {}
};

struct triangle {
    point normal;
    point v1;
    point v2;
    point v3;


    triangle() = default;
    triangle(point normalp, point v1p, point v2p, point v3p) :
            normal(normalp), v1(v1p), v2(v2p), v3(v3p) {}
};

std::vector<triangle> parse_stl(const char* stl_path) {
    using std::fread;
    auto std_file = std::fopen(stl_path, "rb");
    
    char dummy[80];
    fread(dummy, 1, 80, std_file);

    std::uint32_t n_triangles;
    fread(&n_triangles, 4, 1, std_file);

    std::vector<triangle> triangles(n_triangles);
    
    for (auto& tr : triangles){
    	fread(&tr, 48, 1, std_file);
        char dummy[2];
        fread(dummy, 1, 2, std_file);
    }
    
    std::fclose(std_file);
    
    return triangles;
}

constexpr auto stl = "nist.stl";

static void ParseStl(benchmark::State& state) {
    for (auto _ : state) {
        parse_stl(stl);
    }
}

BENCHMARK(ParseStl);

BENCHMARK_MAIN();
