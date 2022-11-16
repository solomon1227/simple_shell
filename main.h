#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>
#include <dirent.h>
/**
 * struct my_alias - aliases in the shell
 * @alias_name: string - aliased name
 * @real_name: string - real name of the aliase
 * Return: The rael name of the aliase
 */

typedef struct my_alias
{
char *alias_name;
char *real_name;
} alias_t;

/**
 * struct my_builtin - Builtin command
 * @builtin_name: string - builtin cmd name
 * @built_fun: pointer to built in function
 * Return: Tthe builtin function corrosponding to the builtin cmd
 */
typedef struct my_builtin
{
char *builtin_name;
char (*built_fun)(void);
} builtin_t;

char *alias_cmp(char *arg);
void execute(char **cmd);
void parse_line(char *line);
char *path_finder(char *cmd);


#endif /* #ifndef MAIN_H */
