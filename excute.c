#include "main.h"
/**
  * execute - excute the comand
  * @cmd: the command and arguments to e executed - array of string
  */
void execute(char **cmd)
{
	unsigned int i;
	char *true_path, *slash = "/";
	char *path;
	char **argv = malloc(2 * sizeof(cmd));
	char **a;

	/*excute the comand*/
	if ((access(cmd[0], F_OK) == 0))
	{
		argv[0] = cmd[0];
		while (cmd[i])
		{
			argv[i] = cmd[i];
			i++;
		}
		argv[i] = cmd[i];

		if (execve(argv[0], argv, NULL) == -1)
		{
			perror("Error");
		}
	}
	else
	{
		path = path_finder(cmd[0]);
		slash = strcat(path, slash);
		true_path = strcat(slash, cmd[0]);
		argv[0] = true_path;
		i = 1;
		while (cmd[i])
		{
			argv[i] = cmd[i];
			i++;
		}
		argv[i] = cmd[i];
		if (execve(argv[0], argv, NULL) == -1)
		{
			perror("Error");
		}
		
	a = argv;
	while (*argv)
		free(*argv++);
	free(a);
	}
}
