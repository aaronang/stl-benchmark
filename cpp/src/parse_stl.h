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