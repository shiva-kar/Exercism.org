#include "raindrops.h"

void convert(char result[], int drops){
    int count = 0;
    if(drops % 3 == 0){
        strcat(result, "Pling");
        count++;
    }
    if(drops % 5 == 0){
        strcat(result, "Plang");
        count++;
    }
    if (drops % 7 == 0){
        strcat(result, "Plong");
        count++;
    }
    if(count == 0){
        sprintf(result, "%d", drops);
    }
}