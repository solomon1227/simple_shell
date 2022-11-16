#include "main.h"

/**
  * path_finder - find the path of an excutable in the path
  * @cmd: comand to be searched for path
  * Return: the path of the cmd
  */

char *path_finder(char *cmd)
{
	DIR *dir_stream;
	struct dirent *entry;
	char *delimiter = ":";
	char *split;
	char *path;

	path = getenv("PATH");
	split = strtok(path, delimiter);

	while (split)
	{
		dir_stream = opendir(split);
		while ((entry = readdir(dir_stream)))
		{
			if (!strcmp(cmd, entry->d_name))
				return (split);
		}
		closedir(dir_stream);
		split = strtok(NULL, delimiter);
	}
	return ("Not found");
}
