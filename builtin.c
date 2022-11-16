#include "main.h"

void (*built(char *cmd))(char **)
{
	int i = 0;

	builtin_t my_builtin[] = {
	{"cd", my_chdir},
	{"exit", Exit},
	{NULL, NULL}
	};

	while (my_builtin[i].builtin_name)
	{
		printf("%d\n", i);
		if (!strcmp(cmd, my_builtin[i].builtin_name))
			return (my_builtin[i].built_fun);
		i++;
	}
	return (NULL);
}

void Exit(char **cmd __attribute__((unused)))
{
	printf("exit\n");
	exit(0);
}

void my_chdir(char **cmd)
{

	char cwd[1024];

	printf("cd\n");
	getcwd(cwd, sizeof(cwd));
	if (!strcmp(cmd[0], cwd))
		if(chdir(cmd[1]) == -1)
			perror("Error");
}
