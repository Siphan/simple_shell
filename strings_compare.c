/* This function compares if two strings are identical */
#include "my_functions.h"
int strings_compare(char *s1, const char *s2)
{
  while(*s1 == *s2++)
    if(*s1++ == 0)
      return 0; /* not the same */
  return (*(const unsigned char *)s1 - *(unsigned char *)(s2-1)); /* returns 1 */
}
