#include "grains.h"

uint64_t square(uint8_t index){
    if(index < 1 || index > 64){
        return 0;
    }
    uint64_t result = 1;
    for (int i = 1; i <= (index-1); ++i) {
        result *= 2;
    }
    return result;
}
uint64_t total(void){
    uint64_t result = 0;
    uint64_t grain = 1;

    for(int i = 1; i <= 64; i++){
            result += grain;
            grain *= 2;
        }
    return result;
}