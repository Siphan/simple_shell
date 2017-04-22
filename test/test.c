  /*
	 * This program is a UNIX command line interpreter
	 * Created by:
	 * Asaia Palacios & Siphan Bou
	 * Date:
	 * May 11, 2016
	 */
#include "libshell.h" /* Library created by Alex Gautier */
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>

/* Prototypes */
char *read_line(const int fd); /* Reads string passed to CL */
char **string_split(const char *str, char separator); /* Splits string passed to CL into parameters to be interpreted */

void C_shell(void)
{
char *line;
char **args;
int status;

do {
  printf("> ");
  line = read_line();
  args = string_split(line);
  status = lsh_execute(args);

  free(line);
  free(args);
  } while (status);
}

int main(__attribute__((unused)) int ac, __attribute__((unused)) char **av, char **env) /* 3rd parameter retrieves environment variables of our programs */
{
  /*
   * execve takes 3 params:
   * file to execute with absolute path,
   * array of arguments passed to main,
   * and array of env var passed to main
   */
  /* execve(file, char **av, char **env) */
  C_shell(); 
  pid_t pid;
  char *exec_argv[] = {"/bin/ls", "-l", NULL};
  int status;

  if ((pid = fork()) == -1) {
    perror("fork");
    return (1);
  }
  if (pid == 0) {
    execve(exec_argv[0], exec_argv, env);
  }
  else {
    wait(&status);
    printf("(Child terminated\n");
  }
  return (0);
}
