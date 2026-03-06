#include "collatz_conjecture.h"

int steps(int start){
    if(start <= 0){
        return -1;
    }
    long long int x = start;
    int steps = 0;
    while(x != 1){
        if(x % 2 == 0){
            x /= 2;
        } else {
            x = (x * 3) + 1;
        }
        steps++;
    }
    return steps;
}