#include "shell.h"
#include <stdlib.h>
/**
** parse_path - Analyse la variable d'environnement
** PATH en listant les répertoires.
 ** Return: Un tableau de répertoires extraits de la variable PATH.
 **/
char **parse_path(void)
{
	int cpt = 1, n = 0;
	char *path, **dirs, *token = NULL;

	path = getenv("PATH");
	if (path == NULL)
		return (NULL);
	while (path[n] != '\0')
	{
		if (path[n] == ':')
			cpt++;
		n++;
	}
	dirs = malloc(sizeof(char *) * (cpt + 1));
	n = 0;
	token = strtok(path, ":");
	while (token != NULL)
	{
		dirs[n] = my_strdup(token);
		token = strtok(NULL, ":");
		n++;
	}
	dirs[n] = NULL;
	return (dirs);
}

/**
 ** resolve_path - Résout une commande dans le chemin d'accès (PATH).
 ** @cmd: Commande recherchée.
 ** @dirs: Tableau des répertoires de la variable d'environnement PATH.
 ** Return: Le chemin d'accès complet de la commande ou NULL si non trouvée.
 **/
char *resolve_path(char *cmd, char **dirs)
{
	char *f_path;
	int n = 0;
	size_t cmdsize = strlen(cmd), arrsize;

	if (access(cmd, X_OK) == 0)
	{
		return (cmd);
	}
	while (dirs[n] != NULL)
	{
		arrsize = strlen(dirs[n]);
		f_path = malloc(sizeof(char) * (cmdsize + arrsize + 2));
		strcpy(f_path, dirs[n]);
		strcat(f_path, "/");
		strcat(f_path, cmd);
		if (access(f_path, X_OK) == 0)
		{
		free(f_path);
		return (f_path);
		}
		free(f_path);
		n++;
	}
	return (NULL);
}
