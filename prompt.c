#include "shell.h"
/**
 ** prompt - Affiche le prompt et lit la commande.
 ** Return: Retourne la commande (cmd) ou NULL si vide ou rien n'est saisi.
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
