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

#ifndef PARSE_STL_H
#define PARSE_STL_H

#include <string>
#include <vector>

namespace stl {

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

    std::vector<triangle> parse_stl(const std::string &stl_path);

}

#endif