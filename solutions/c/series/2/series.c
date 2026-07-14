#include <string.h>
#include <stdlib.h>
#include "series.h"


unsigned int stringCount(char *input);

slices_t slices(char *input_text, unsigned int substring_length)
{
    unsigned int length = stringCount(input_text);
    slices_t slices = {.substring_count = 0, .substring = malloc(sizeof(char *))};
    if (substring_length <= length && substring_length != 0) {
      slices.substring_count = length - substring_length + 1;
      slices.substring = realloc(slices.substring, sizeof(char *) * slices.substring_count);
      for (unsigned int i = 0; i < slices.substring_count; i++){
        slices.substring[i] = malloc(sizeof(char) * (substring_length + 1));
        strncpy(slices.substring[i], input_text+i, substring_length);
        slices.substring[i][substring_length] = '\0';
      }
    }
    return slices;
}

unsigned int stringCount(char *input) {
    if (!input) {
        return 0;
    }
    int length = 0;
    while (input[length] != '\n' && input[length] != '\0') {
        length++;
    }
    return length;
}
