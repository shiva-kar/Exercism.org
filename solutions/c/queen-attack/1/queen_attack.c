#include "queen_attack.h"

attack_status_t can_attack(position_t queen_1, position_t queen_2){
    if((queen_1.row > 7 || queen_2.row > 7 || queen_1.column > 7 || queen_2.column > 7)) return 2;
    if(queen_1.row == queen_2.row && queen_1.column == queen_2.column) return 2;
    if(queen_1.row == queen_2.row || queen_1.column == queen_2.column) return 1;
    for(uint8_t i = 1; i < 8; i++){
        if(queen_1.row-i == queen_2.row && queen_1.column-i == queen_2.column) return 1;
        if(queen_1.row+i == queen_2.row && queen_1.column-i == queen_2.column) return 1;
        if(queen_1.row-i == queen_2.row && queen_1.column+i == queen_2.column) return 1;
        if(queen_1.row+i == queen_2.row && queen_1.column+i == queen_2.column) return 1;
    }
    return 0;
}