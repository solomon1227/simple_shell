#include "main.h"
/**
  * execute - excute the comand
  * @cmd: the command and arguments to e executed - array of string
  */
void execute(char **cmd)
{
	unsigned int i;
	char *path;
	char **argv = malloc(2 * sizeof(cmd));
	/*pid_t child_pid;*/

	if ((access(cmd[0], F_OK) == 0))
		path = cmd[0];
	else
		path = path_finder(cmd[0]);
	if (path != NULL)
	{
		argv[0] = path;
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
			exit(EXIT_FAILURE);
		}
	}
	else
		printf("%s: command not found\n", cmd[0]);
}
