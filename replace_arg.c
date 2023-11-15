#include "shell.h"
/**
 ** rep_st_arg - Remplace le premier élément du tableau
 ** d'arguments par le chemin complet de la commande.
 ** @args: Tableau de la commande et de ses arguments.
 ** @f_path: Chaîne représentant le chemin complet de la commande.
 ** Return: Tableau de la commande avec le chemin complet.
 **/

char **rep_st_arg(char **args, const char *f_path)
{
	if (args == NULL || f_path == NULL)
	{
	return (args);
	}
	free(args[0]);
	args[0] = my_strdup(f_path);
	if (args[0] == NULL)
	{
		return (args);
	}
	return (args);
}
