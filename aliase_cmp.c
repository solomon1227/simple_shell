#include "main.h"

/**
  * alias_cmp - searches for the aliases
  * @arg: arguments to be searched if it is an alias
  * Return: the real name
  */
char *alias_cmp(char *arg)
{
	int i = 0;

	alias_t my_aliases[] = {
	{"egrep", "egrep --color=auto"},
	{"fgrep", "fgrep --color=auto"},
	{"grep", "grep --color=auto"},
	{"l", "ls -CF"},
	{"la", "ls -a"},
	{"ll", "ls -alF"},
	{"ls", "ls --color=auto"},
	{NULL, NULL}
	};

	while (my_aliases[i].alias_name)
	{
		if (!strcmp(arg, my_aliases[i].alias_name))
			return (my_aliases[i].real_name);
		i++;
	}
	return (arg);
}
