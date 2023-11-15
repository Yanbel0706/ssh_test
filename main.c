#include "shell.h"
#include <stdlib.h>
/**
 ** main - main program
 ** @ac: arguments count
 ** @av: arguments array
 ** @env: environment variables array
 ** Return: 0 if success, -1 if error
 **/
int main(int ac, char **av, char **env)

{
  char *cmd = NULL, **args;
  int cmd_cpt = 0, exec_status = 0;
  char **dirs = parse_path();
  ac = ac;

  while (1)
  {
      cmd = prompt();
      if (cmd == NULL)
	  break;
      if (is_not_empty(cmd) == 0)
      {
	  free(cmd);
	  continue;
			                                                                                      }
      
      if (strncmp(cmd, "env", 3) == 0)
      {
	  print_env(env);
	  free(cmd);
	  continue;
      }
      
      if (cmd[0] != '\0')
      {
	  args = split_cmd(cmd);
	  exec_status = command_exec(args, dirs, av[0], cmd_cpt);
          free(cmd);
	  cmd_cpt++;
	  free_arr(args);
      }
      
      else
	  free(cmd);
  }
  free(cmd);
  free_arr(dirs);
  if (exec_status != 0 && isatty(STDIN_FILENO) == 0)
     exit(exec_status);
  else
     exit(0);
  return 0;
}
