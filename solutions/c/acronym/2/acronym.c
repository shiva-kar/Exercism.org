#include "acronym.h"

#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

char *abbreviate(const char *phrase) {
  if (phrase == NULL)
    return NULL;

  if (*phrase == '\0')
    return NULL;

  size_t capacity = 8;
  char *result = malloc(capacity);

  if (result == NULL)
    return NULL;

  bool can_add = true;
  size_t count = 0;

  for (size_t index = 0; phrase[index] != '\0'; index++) {
    char c = phrase[index];

    if (c == ' ' || c == '-' || c == '_') {
      can_add = true;
      continue;
    }

    if (!isalnum((unsigned char)c))
      continue;

    if (isupper((unsigned char)c) && index > 0 &&
        islower((unsigned char)phrase[index - 1])) {
      can_add = true;
    }

    if (!can_add)
      continue;

    if (count + 1 >= capacity) {
      capacity *= 2;

      char *temp = realloc(result, capacity);

      if (temp == NULL) {
        free(result);
        return NULL;
      }

      result = temp;
    }

    result[count++] = (char)toupper((unsigned char)c);
    result[count] = '\0';

    can_add = false;
  }

  return result;
}
