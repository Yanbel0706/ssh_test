#include "shell.h"

/**                                                                                                      ** rep_st_arg - replaces the first element of the args array                                           ** with the full command path                                                                         
** @args: the array of the command and it's arguments                                                   ** @f_path: string of the full path of the command                                                   
** Return: the array of the command with the full path                                                 **/ 

char **rep_st_arg(char **args, const char *f_path)
{
    if (args == NULL || f_path == NULL) 
        {
	return args;
	}
    free(args[0]);
    args[0] = my_strdup(f_path);
    if (args[0] == NULL) 
    {
	    return args;
    }
    return args;
}
