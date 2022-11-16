#include "main.h"
/**
  * execute - excute the comand
  * @cmd: the command and arguments to e executed - array of string
  * @path: path of the command
  */
void execute(char *path, char **cmd)
{
	unsigned int i;
	char **argv = malloc(2 * sizeof(cmd));
	/*pid_t child_pid;*/

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
