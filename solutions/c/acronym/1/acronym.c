#include "acronym.h"
#include <ctype.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

char *abbreviate(const char *phrase) {
  if (!phrase)
    return NULL;
  size_t length = strlen(phrase);
  if (!length) {
    return NULL;
  }
  bool can_add = true;
  size_t capacity = 8;
  char *result = (char *)malloc(capacity * sizeof(char));
  if (!result) {
    return NULL;
  }
  size_t count = 0;
  size_t index = 0;
  char c = phrase[index];
  while (c != '\0') {
    if (c == ' ' || c == '-' || c == ',' || c == '_') {
      can_add = true;
      index++;
      c = phrase[index];
      continue;
    } else if (can_add == true) {
      if (count == capacity-1) {
        capacity *= 2;
        result = realloc(result, sizeof(char) * capacity);
        if (!result) {
          return NULL;
        }
      }
      c = toupper(c);
      result[count] = c;
      index++;
      c = phrase[index];
      result[count+1] = '\0';
      count++;
      can_add = false;
      continue;
    } else {
      index++;
      c = phrase[index];
    }
  }
  return result;
}
