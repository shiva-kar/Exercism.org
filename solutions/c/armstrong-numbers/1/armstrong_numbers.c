#include "armstrong_numbers.h"

bool is_armstrong_number(int candidate){
    int original = candidate;
    int remainder = 0;
    int result = 1;
    int count = 0;
    int final = 0;

    if (candidate == 0){
        count++;
    } else while (candidate != 0) {
        candidate /= 10;
        count++;
    }

    candidate = original;
    
    while (candidate > 0) {
        remainder = candidate % 10;
        candidate /= 10;
        for(int i = 0; i < count; i++){
            result *= remainder;
        }
        final += result;
        result = 1;
    }
    
    if(final == original){
        return true;
    } else{
        return false;    
    }
}