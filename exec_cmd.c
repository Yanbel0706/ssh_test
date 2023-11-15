#include"shell.h"
/**
**command_exec- executes acommand
**@args: command and it's arguments
**@path_array:array of path variable directories
**@prog_name:program name
**@cmd_cpt:number of the command
**Return: return 0 onsuccess -2 if it fails in non-interactive
** and -1 in interactive
**/
int command_exec(char **args, char **path_array, char *prog_name, int cmd_cpt)
{
	char *f_path;
	pid_t child_p;
	int status = 0, exit_s = 0;

	if (strncmp(args[0], "cd ", 2) == 0)
	{
		change_dir(args);
		return (0);
	}
	f_path = resolve_path(args[0], path_array);
	if (f_path != NULL)
	{
		if (args[0] != f_path)
			rep_st_arg(args, f_path);
		child_p = fork();
		if (child_p == 0)
		{
			execve(args[0], args, environ);
		}
		else if (child_p < 0)
		{
			perror("Forkfailure");
			exit(EXIT_FAILURE);
		}
		else
		{
			exit_s = wait_process(child_p, status);
			return (exit_s);
		}
	}
	else
	{
		fprintf(stderr, "%s: %d: %s: not found\n", prog_name, cmd_cpt, args[0]);
	}
	return (0);
}


/**
**wait_process - retourne les tatut de sortie d'un processus
**@pid:le PID du processus
**@status:le statut du processus
**Return:le statut de sortie sur succès, 0  sinon
**/
int wait_process(pid_t pid, int status)
{
	int exit_s = 0;

	waitpid(pid, &status, 0);

	if (WIFEXITED(status))
	{
		exit_s = WEXITSTATUS(status);
		return (exit_s);
	}
	return (0);
}

