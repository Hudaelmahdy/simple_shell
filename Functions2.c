#include "shell.h"

/**
 *execute - function to excute command
 *@command: pointer
 *@name:name of the shell
 *@env: pointer to enviromental variables
 *@cycles: number of cycles
 *Return: nothing
 */

void execute(char **command, char *name, char **env, int cycles)
{
	char **path_array = NULL, *absolute_path = NULL;
	struct stat st;
	unsigned int i = 0;

	if (str_cmp(command[0], "env") != 0)
		print_env(env);
	if (stat(command[0], &st) == 0)
	{
		if (execve(command[0], command, env) < 0)
		{
			perror(name);
			free_exit(command);
		}
	}
	else
	{
		path_array = _getpath(env);
		while (path_array[i])
		{
			absolute_path = str_cat(path_array[i], command[0]);
			i++;
			if (stat(absolute_path, &st) == 0)
			{
				if (execve(absolute_path, command, env) < 0)
				{
					perror(name);
					free_double_pointer(path_array);
					free_exit(command);
				}
				return;
			}
		}
		error(name, cycles, command);
		free_double_pointer(path_array);
	}
}

/**
 *print_env - function that prints all variables
 *@env: pointer to enviroment varaibles
 *Retun: nothing
 */

void print_env(char **env)
{
	size_t i = 0, len = 0;

	while (env[i])
	{
		len = str_len(env[i]);
		write(STDOUT_FILENO, env[i], len);
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
}

/**
 *_getpath - function to gets the path
 *@env: pointer to enviromental variables
 *Return: all paths
 */

char **_getpath(char **env)
{
	char *path_value = NULL, **path_array = NULL;
	unsigned int i = 0;

	path_value = strtok(env[i], "=");
	while (env[i])
	{
		if (str_cmp(path_value, "PATH"))
		{
			path_value = strtok(NULL, "\n");
			path_array = tokening(path_value, ":");
			return (path_array);
		}
		i++;
		path_value = strtok(env[i], "=");
	}
	return (NULL);
}

/**
 *error - function to prints error
 *@name: name of the shell
 *@cycles: number of cycles
 *@command: pointer
 *Return: nothing
 */

void error(char *name, int cycles, char **command)
{
	char c;

	c = cycles + '0';
	write(STDOUT_FILENO, name, strlen(name));
	write(STDOUT_FILENO, ": ", 2);
	write(STDOUT_FILENO, &c, 1);
	write(STDOUT_FILENO, ": ", 2);
	write(STDOUT_FILENO, command[0], strlen(command[0]));
	write(STDOUT_FILENO, ": not found\n", 12);
}
