#include "queen_attack.h"
#include <stdlib.h>
#include <stdbool.h>

static inline bool is_valid_position(const position_t position) {
    return position.row <= 7 && position.column <= 7;
}

attack_status_t can_attack(position_t queen_1, position_t queen_2) {
    if (!is_valid_position(queen_1) || !is_valid_position(queen_2)) return INVALID_POSITION;
    if (queen_1.row == queen_2.row && queen_1.column == queen_2.column) return INVALID_POSITION;

    int v_diff = abs((int)queen_1.row - (int)queen_2.row);
    int h_diff = abs((int)queen_1.column - (int)queen_2.column);

    if (v_diff == 0 || h_diff == 0 || v_diff == h_diff) return CAN_ATTACK;
    return CAN_NOT_ATTACK;
}