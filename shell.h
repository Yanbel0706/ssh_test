#ifndef SHELL_H
#define SHELL_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <ctype.h>
#include <fcntl.h>
#include <errno.h>

extern char **environ;

char **parse_path(void);
char *resolve_path(char *cmd, char **dirs);
char *prompt(void);
int command_exec(char **args, char **path_array,
				char *prog_name, int cmd_cpt);
char **split_cmd(char *cmd);
char *my_strdup(const char *s);
char **rep_st_arg(char **args, const char *f_path);
void change_dir(char **args);
void print_env(char **env);
void free_arr(char **arr);
int is_not_empty(char *command);
int wait_process(pid_t pid, int status);

#endif
