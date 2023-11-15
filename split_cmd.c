#include "shell.h"
/**
 ** split_cmd - Découpe les parties de la commande et les stocke
 ** dans un tableau de chaînes de caractères.
 ** @cmd: Commande à traiter.
 ** Return: Un pointeur vers le tableau de chaînes de caractères.
 **/
char **split_cmd(char *cmd)
{
	char *token = NULL, **array = NULL;
	int i = 0;

	cmd = cmd;
	token = strtok(cmd, " ");

	while (token != NULL)
	{
		array = realloc(array, sizeof(char *) * (i + 1));
		array[i] = my_strdup(token);
		token = strtok(NULL, " ");
		i++;
	}
	array = realloc(array, sizeof(char *) * (i + 1));
	array[i] = NULL;
return (array);
}

/**
 ** my_strdup - Duplique une chaîne de caractères.
 ** @s: La chaîne de caractères d'entrée à dupliquer.
 ** Return: Un pointeur vers la nouvelle chaîne dupliquée
 ** récemment allouée.
 ** NULL si l'allocation de mémoire échoue
 ** ou si la chaîne d'entrée est NULL.
 **/
char *my_strdup(const char *s)
{
	size_t len;
	char *dup;

	if (s == NULL)
		return (NULL);
	len = strlen(s) + 1;
	dup = malloc(len);
	if (dup == NULL)
		return (NULL);
	return  (strcpy(dup, s));
}
