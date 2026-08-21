#include "eliuds_eggs.h"

unsigned int egg_count(unsigned int egg){
    unsigned int count = 0;
    int size = sizeof(int) * 8;
    for(int i = 0; i < size; i++){
        if(egg & 1)count++;
        egg = egg >> 1;
    }
    return count;
}