#include "main.h"

/**
  * built - builtin function
  * @cmd: command
  * Return: pointer to builtin function
  */

void (*built(char *cmd))(char **)
{
	int i = 0;

	builtin_t my_builtin[] = {
	{"cd", my_chdir},
	{"exit", Exit},
	{"env", Env},
	{NULL, NULL}
	};

	while (my_builtin[i].builtin_name)
	{
		if (!strcmp(cmd, my_builtin[i].builtin_name))
			return (my_builtin[i].built_fun);
		i++;
	}
	return (NULL);
}

/**
  * Exit - builtin function
  * @cmd: command
  */
void Exit(char **cmd __attribute__((unused)))
{
	exit(0);
}

/**
  * my_chdir - builtin function
  * @cmd: command
  */
void my_chdir(char **cmd)
{

	char cwd[1024];

	getcwd(cwd, sizeof(cwd));
	if (!strcmp(cmd[0], cwd))
		if (chdir(cmd[1]) == -1)
			perror("Error");
}

/**
  * Env - builtin function
  * @cmd: command
  */
void Env(char **cmd __attribute__((unused)))
{
	int i = 0;

	while (environ[i])
	{
		if (environ[i])
			printf("%s\n", environ[i]);
		i++;
	}
}
