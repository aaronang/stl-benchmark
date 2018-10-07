#include <fstream>
#include <iostream>
#include "benchmark/benchmark.h"

struct point {
    float x;
    float y;
    float z;

    point(float xp, float yp, float zp) : x(xp), y(yp), z(zp) {}
};

struct triangle {
    point normal;
    point v1;
    point v2;
    point v3;

    triangle(point normalp, point v1p, point v2p, point v3p) :
            normal(normalp), v1(v1p), v2(v2p), v3(v3p) {}
};

std::vector<triangle> parse_stl(const std::string &stl_path) {
    std::ifstream stl_file(stl_path.c_str(), std::ios::in | std::ios::binary);

    // skip header
    char header_info[80];
    stl_file.read(header_info, 80);

    char n_triangles[4];
    stl_file.read(n_triangles, 4);
    auto *r = (unsigned int *) n_triangles;
    unsigned int num_triangles = *r;

    std::vector<triangle> triangles;
    triangles.reserve(num_triangles);

    for (unsigned int i = 0; i < num_triangles; i++) {
        float fs[12];
        stl_file.read((char *) fs, 48);
        point normal{fs[0], fs[1], fs[2]};
        point v1{fs[3], fs[4], fs[5]};
        point v2{fs[6], fs[7], fs[8]};
        point v3{fs[9], fs[10], fs[11]};
        triangles.emplace_back(normal, v1, v2, v3);

        // skip attribute byte count
        char dummy[2];
        stl_file.read(dummy, 2);
    }

    assert(stl_file.peek() == EOF);

    return triangles;
}

static void ParseStl(benchmark::State& state) {
    std::string stl = "nist.stl";
    for (auto _ : state) {
        parse_stl(stl);
    }
}

BENCHMARK(ParseStl);

BENCHMARK_MAIN();
