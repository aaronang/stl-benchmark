#include <fstream>

#include "parse_stl.h"

namespace stl {
    float parse_float(std::ifstream &s) {
        char f_buf[sizeof(float)];
        s.read(f_buf, 4);
        auto *fptr = (float *) f_buf;
        return *fptr;
    }

    point parse_point(std::ifstream &s) {
        float x = parse_float(s);
        float y = parse_float(s);
        float z = parse_float(s);
        return {x, y, z};
    }

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

        for (unsigned int i = 0; i < num_triangles; i++) {
            auto normal = parse_point(stl_file);
            auto v1 = parse_point(stl_file);
            auto v2 = parse_point(stl_file);
            auto v3 = parse_point(stl_file);
            triangles.emplace_back(triangle(normal, v1, v2, v3));

            // skip attribute byte count
            char dummy[2];
            stl_file.read(dummy, 2);
        }

        assert(stl_file.peek() == EOF);

        return triangles;
    }

}