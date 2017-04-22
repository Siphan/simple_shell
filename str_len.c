#include "my_functions.h"
int str_len(const char *str)
{
  int total = 0;
  while (*str != 0) {
    total++;
      str++;
    }
    return total; /* return length of string */
}
