#include "shell.h"

/**
 ** print_env - prints the current working environment
 ** @env: the environment variable
 **/
void print_env(char **env)
{
int n;

   if (env == NULL) 
     {
        fprintf(stderr, "Error: Environment variable is NULL.\n");
        return;
     }

   for (n = 0; env[n] != NULL; n++)
     { 
	printf("%s\n", env[n]);
     }
     
     
}
