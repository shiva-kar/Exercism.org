#include "armstrong_numbers.h"

bool is_armstrong_number(int candidate) {
    int original = candidate;
    int count = 0;
    int sum = 0;
    int temp = candidate;

    do {
        temp /= 10;
        count++;
    } while (temp != 0);

    temp = candidate;
    
    while (temp != 0) {
        int digit = temp % 10;
        temp /= 10;

        int power = 1;
        for (int i = 0; i < count; i++) {
            power *= digit;
        }

        sum += power;
    }
    return sum == original;
}