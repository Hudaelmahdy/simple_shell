#include "shell.h"

/**
 *lookup_builtin - function to check built in commands
 *@argv: arguments
 *Return: pointer to function
 */

void(*lookup_builtin(char **argv))(char **argv)
{
	int i, j;
	builtin commands[] = {
		{"exit", exit_shell},
		{"env", printenv},
		{"setenv", set_env},
		{"unsetenv", unset_env},
		{NULL, NULL}
	};
for (i = 0; commands[i].name; i++)
{
	j = 0;
	if (commands[i].name[j] == argv[0][j])
	{
		for (j = 0; argv[0][j]; j++)
		{
			if (commands[i].name[j] != argv[0][j])
				break;
		}
		if (!argv[0][j])
			return (commands[i].func);
		}
	}
	return (0);
}
