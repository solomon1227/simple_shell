#include "main.h"

/**
  * parse_line - split the line into tokens
  * @line: line read
  */
void parse_line(char *line)
{

	unsigned int counter = 0;
	char *token;
	char **toks;
	unsigned int capacity = 1024;
	char *delim = " \t\r\n";


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
	/* Calling excute functio*/
	execute(toks);
}
