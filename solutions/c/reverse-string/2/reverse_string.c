#include "reverse_string.h"
#include <string.h>
#include <stdlib.h>
char *reverse(const char *value){
    int length = strlen(value);
    char *ptr1 = malloc(length+1);
    strcpy(ptr1, value);
    if(*value == '\0'){
        return ptr1;
    }
    char *ptr2 = ptr1;
    ptr2 += length-1;
    for(int i = 1; i <= (length/2); i++){
        char temp = *ptr1;
        *ptr1 = *ptr2;
        *ptr2 = temp;
        ptr1++;
        ptr2--;
    }
    return (ptr1 - length/2);
}