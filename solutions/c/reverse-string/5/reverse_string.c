#include "reverse_string.h"
#include "string.h"
#include "stdlib.h"

char *reverse(const char *value) {
    int length = 0;
    char c = value[0];
    while(c != '\0'){
        length++;
        c = value[length];
    }
    char *reverse = malloc(sizeof(char) * length);
    strcpy(reverse, value);
    char *ptr1 = &reverse[0];
    char *ptr2 = &reverse[length-1];

    for(int i = 0; i < length/2; i++){
        char temp = *ptr1;
        *ptr1 = *ptr2;
        *ptr2 = temp;
        ptr1++;
        ptr2--;
    }
    return reverse;
}