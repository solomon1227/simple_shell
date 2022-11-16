#include "main.h"

/**
  * main - infinite loop until exit
  * @ac: length of argunments
  * @av: array of main argunments
  *
  * Return: 0 on success, 1 otherwise
  */
int main(int ac __attribute__((unused)), char **av __attribute__((unused)))
{
	pid_t child_pid;
	int status;
	int int_mode = 1;
	char cwd[1024];
	char *line;
	ssize_t nread;
	size_t len;

	while (int_mode)
	{
		int_mode = isatty(STDIN_FILENO);
		if (int_mode == 1)
		{
			getcwd(cwd, sizeof(cwd));
			printf("%s@", cwd);
			printf("%s:\n", getenv("USER"));
			write(STDOUT_FILENO, "$ ", 2);
		}

		line = NULL;
		len = 0;

		nread = getline(&line, &len, stdin);
		if (nread == -1)
		{
			perror("error");
		}
		child_pid = fork();
		if (child_pid < 0)
			perror("Error");
		if (child_pid == 0)
			parse_line(line);	/*parse the line*/
		else
			wait(&status);

		free(line);
	}
	return (0);
}
