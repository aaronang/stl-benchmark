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

}