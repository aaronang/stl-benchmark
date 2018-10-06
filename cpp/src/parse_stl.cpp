/**
 * The MIT License (MIT)
 *
 * Copyright (c) 2016 dillonhuff
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#include <fstream>

#include "parse_stl.h"

namespace stl {

    inline float parse_float(std::ifstream &s) {
        char buffer[sizeof(float)];
        s.read(buffer, 4);
        auto *fptr = (float *) buffer;
        return *fptr;
    }

    inline point parse_point(std::ifstream &s) {
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
        triangles.reserve(num_triangles);

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