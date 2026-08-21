#include "queen_attack.h"

attack_status_t can_attack(position_t queen_1, position_t queen_2){
    if((queen_1.row > 7 || queen_2.row > 7 || queen_1.column > 7 || queen_2.column > 7)) return 2;
    if(queen_1.row == queen_2.row && queen_1.column == queen_2.column) return 2;
    if(queen_1.row == queen_2.row || queen_1.column == queen_2.column) return 1;

   uint8_t row_diff;
uint8_t column_diff;
    if(queen_1.row > queen_2.row && queen_1.column > queen_2.column){
        row_diff = queen_1.row - queen_2.row;
        column_diff = queen_1.column - queen_2.column;
    } else if(queen_1.row < queen_2.row && queen_1.column < queen_2.column){
        row_diff = queen_2.row - queen_1.row;
        column_diff = queen_2.column - queen_1.column;
    } else if(queen_1.row > queen_2.row && queen_1.column < queen_2.column){
        row_diff = queen_1.row - queen_2.row;
        column_diff = queen_2.column - queen_1.column;
    } else {
        row_diff = queen_2.row - queen_1.row;
        column_diff = queen_1.column - queen_2.column;
    }
        if(row_diff == column_diff) return 1;
    
    return 0;
}