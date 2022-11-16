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
	char *true_path, *slash = "/";
	char *delimiter = ":";
	char *split;
	char *path;

	path = getenv("PATH");
	split = strtok(path, delimiter);
	if ((access(cmd, F_OK) == 0))
		return (cmd);
	while (split)
	{
		dir_stream = opendir(split);
		while ((entry = readdir(dir_stream)))
		{
			if (!(strcmp(cmd, entry->d_name)))
			{
				slash = strcat(split, slash);
				true_path = strcat(slash, cmd);
				return (true_path);
			}
		}
		closedir(dir_stream);
		split = strtok(NULL, delimiter);
	}
	return (NULL);
}
