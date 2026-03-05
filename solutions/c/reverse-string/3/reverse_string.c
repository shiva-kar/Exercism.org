#include "reverse_string.h"
#include <string.h>
#include <stdlib.h>

char *reverse(const char *value) {
    int length = strlen(value);
    char *result = malloc(length + 1);
    strcpy(result, value);
    char *left = result;
    char *right = result + length - 1;
    for (int i = 0; i < length / 2; i++) {
        char temp = *left;
        *left = *right;
        *right = temp;
        left++;
        right--;
    }
    return result;
}