#include "shell.h"
/**
 ** free_arr - to free an array of strings
 ** @arr: array to be treated
 **/
void free_arr(char **arr)
{
	int n = 0;

	while (arr[n] != NULL)
	{
		free(arr[n]);
		n++;
	}
	free(arr);
}

/**
 ** is_not_empty - vérifie si la commande est vide
 ** @command: la commande à traiter
 ** Return: 0 si vide, 1 si non vide
 **/
int is_not_empty(char *command)
{
	int n;

	for (n = 0; command[n] != '\0'; n++)
	{
		if (isalnum(command[n]) != 0)
			return (1);
	}
	return (0);
}
