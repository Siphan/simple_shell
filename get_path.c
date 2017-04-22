/* This program looks for the path of commands input by user */
#include "my_functions.h"
#include "libshell.h"
#include <stddef.h>

int str_len(const char *str);

char *get_path(char **env , char *cmd)
{
  char **path;
  char *dir_path;
  int i;
  char **unique_path;
  char *concat_path;
  char *cmd_path;
  for (i = 0; env[i]!= '\0'; i++) /* Loops through each string in env ie each environment variable */
  {
    if(str_ncomp(env[i], "PATH=", str_len("PATH=")) == 0) /* Looks for a string containing "PATH=" */
      {
        path = string_split(env[i],'='); /* Separates the string found into 2 strings; "PATH" and what comes after */
        dir_path = path[1]; /* The second string ie the whole path is stored */
        unique_path = string_split(dir_path, ':'); /* The whole path contained in env var PATH is divided into all possible paths to search for input command */
        break; /* Gets the unique_paths */
      }
  }
  for(i = 0; unique_path[i] != '\0'; i++)
   {
     concat_path = concat_strings(unique_path[i],"/"); /* "/" is appended to each unique path */
     cmd_path = concat_strings(concat_path, cmd); /* Input command is appended to each unique path */
     if(find_ex(cmd_path)) /* If path to program to be executed is found */
        return cmd_path;
        cmd_path = '\0';
   }
   return NULL; /* If no path found */
}
