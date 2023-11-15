#include "shell.h"
/**                                                                                                     
**split_cmd - splits the command parts and stores them in an array of strings                  
**@command: command to be treated                                                                      
**Return: a pointer to the array of strings                                                            
**/                                                                                                    
char **split_cmd(char *cmd)                                                                     
{                                                                                                       
	char *token = NULL, **array = NULL;                                                                     int i = 0;
	cmd = cmd;                                                                                      
	token = strtok(cmd, " ");                                                                               while (token != NULL)                                                                                   
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
 ** my_strdup - Duplicates a string.
 ** @s: The input string to be duplicated.
 ** Return: A pointer to the newly allocated duplicated string.
 **NULL if memory allocation fails or if the input string is NULL.
 **/
char *my_strdup(const char *s) {                                                                           
	size_t len;                                                                                                                                                                                                      char *dup;                                                                                                                                                                                                      if (s == NULL)                                                                                                                                                                                                          return NULL;                                                                                                                                                                                                                                                                                                                                                                                                            

	len = strlen(s) + 1;                                                                                                                                                                                            
	dup = malloc(len);                                                                                                                                                                                              if (dup == NULL)                                                                                                                                                                                                    return NULL;                                                                                                                                                                                                                                                                                                                                                                                                                return  strcpy (dup, s);    

}       
