#include "reverse_string.h"
#include "string.h"
#include "stdlib.h"
char *reverse(const char *value){
    int index = strlen(value);
    char *ptr = malloc(index+1);
    strcpy(ptr, value);
    char *ptr2 = ptr;
    char *reversed = ptr;
        if(*value == '\0'){
        return reversed;
    }
    
    while(*ptr2 != '\0'){
        ptr2++;
    } ptr2--;
    for(int i = 0; i < (index/2); i++){
        char temp = *ptr;
        *ptr = *ptr2;
        *ptr2 = temp;
        ptr++;
        ptr2--;
    }
    return reversed;
}