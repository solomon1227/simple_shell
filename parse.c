#include "main.h"

/**
  * parse_line - split the line into tokens
  * @line: line read
  */
void parse_line(char *line)
{

	unsigned int counter = 0;
	char *token, *path;
	char **toks;
	unsigned int capacity = 1024;
	char *delim = " \t\r\n";
	void (*fun_ptr)(char **);


	/*parse the line*/
	toks = malloc(sizeof(char) * capacity);
	token = strtok(line, delim);
	while (token != NULL)
	{
		toks[counter] = token;
		counter++;
		if (counter >= capacity)
		{
			capacity *= 2;
			toks = realloc(toks, capacity * sizeof(char));
		}
		token = strtok(NULL, delim);
	}
	toks[counter] = token;
	fun_ptr = built(toks[0]);
	if (fun_ptr != NULL)
	{
		fun_ptr(toks);
	}
	else
	{
		path = path_finder(toks[0]);
		if (path != NULL)
		{
			execute(path, toks);
		}
		else
			printf("%s: command not found\n", toks[0]);
	}
}
