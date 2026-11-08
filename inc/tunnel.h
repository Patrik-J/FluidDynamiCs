#ifndef TUNNEL_H
#define TUNNEL_H

#include <cmath>
#include "vector.h"

namespace CFD {
    struct Tunnel {
        Vector2 top_left_corner;
        Vector2 bottom_right_corner;

        float width() {
            return std::fabsf(bottom_right_corner[0] - top_left_corner[0]);
        };

        float height() {
            return std::fabsf(bottom_right_corner[1] - top_left_corner[1]);
        };
    };  
}   

#endif 