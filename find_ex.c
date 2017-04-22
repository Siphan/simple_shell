/* This function checks if a program exists for an input command */
#include "my_functions.h"
#include "libshell.h"
#include <sys/stat.h>

int find_ex(char *s)
{
  struct stat file_ex;

  if (lstat(s, &file_ex) == -1)
    {
      return (0);
    } else {
    return (1);
  }
}
