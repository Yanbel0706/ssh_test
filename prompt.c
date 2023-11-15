#include "shell.h"

/**                                                                                                     ** prompt - displays the prompt and read the command                                   
** Return: return the command (cmd), or NULL if empty or nothing typed
**/                                                                                                    
char *prompt(void)                                                                                      
{                                                                                                       
char *cmd = NULL;                                                                                   
size_t n = 0;                                                                                           
ssize_t size;                                                                                           
if (isatty(STDIN_FILENO) == 1)                                                                          
	printf("($) ");                                                                                         
size = getline(&cmd, &n, stdin);                                                                    
if (feof(stdin) != 0)                                                                                   
{                                                                                                       
	free(cmd);                                                                                          
	return (NULL);                                                                                          
}                                                                                                       
if (strncmp(cmd, "exit", 4) == 0)                                                                   
{                                                                                                       
	free(cmd);                                                                                          
	return (NULL);                                                                                          
}                                                                                                       
cmd[size - 1] = '\0';                                                                               
return (cmd);                                                                                       
}  
