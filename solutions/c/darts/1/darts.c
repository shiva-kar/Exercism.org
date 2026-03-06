#include "darts.h"

uint8_t score(coordinate_t coords){
    float point_sq = (coords.x * coords.x) + (coords.y * coords.y);
    const float r_inner_sq = 1.0f, r_middle_sq = 25.0f, r_outer_sq = 100.0f;
    if(point_sq <= r_inner_sq) return 10;
    if(point_sq <= r_middle_sq) return 5;
    if(point_sq <= r_outer_sq) return 1;
    return 0;
}