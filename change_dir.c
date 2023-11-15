#include "shell.h"
/**                                                                                                      
** change_dir - changes directory                                                                       
** @args: directory path                                                                                
**/                                                                                                    
void change_dir(char **args) 
{                                                                           
   char *new_dir;
   char *pwd;
    if (args[1] == NULL)
         {
               new_dir = getenv("HOME");
         }
     else
         {
               new_dir = args[1];
         }
    
    
     if (chdir(new_dir) != 0)
         {
             perror("cd"); 
         }
     else
         {
   
           pwd = getcwd(NULL, 0);
           if (pwd != NULL)
                                                                                                                 {
               setenv("PWD",pwd, 1);                                                                                   free(pwd);                             
														 }
                                                                                                                else
                                                                                                                 {
               perror("getcwd");
                                                                                                                 }
                                                                                                                 }
                                                                                                        }
