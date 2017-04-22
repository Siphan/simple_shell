/* In C, the exec family function executes a program within your own program */
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>

/* Prototypes */
char *read_line(const int fd); /* Reads string passed to CL */
char **string_split(const char *str, char separator); /* Splits string passed to CL into parameters to be interpreted */

int main(__attribute__((unused)) int ac, __attribute__((unused)) char **av, char **env) /* 3rd parameter retrieves environment variables of our programs */
{
  /*
   * execve takes 3 params:
   * file to execute with absolute path,
   * array of arguments passed to main,
   * and array of env var passed to main
   */
/* execve(file, char **av, char **env) */

  pid_t pid;
  char *exec_argv[] = {"/bin/echo", "Holberton", NULL}; /* Executes ls program with the option -l */
  int status;

  if ((pid = fork()) == -1) {
    perror("fork");
    return (1);
  }
  if (pid == 0) { /* Program ls replaces our program in child process */
    execve(exec_argv[0], exec_argv, env);
  }
  else {
    wait(&status);
    printf("Child terminated\n");
  }
  return (0);
}
