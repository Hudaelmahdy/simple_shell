#include "shell.h"

/**
*exit_shell - function to exit shell
*@argv: array
*@string: string
*@_exit: value
*Return: nothing
*/

void exit_shell(char **argv, char *string, int _exit)
{
	int status = 0;

	if (argv[1])
	{
		free(string);
		free(argv);
		exit(_exit);
	}
	status = atoi(argv[1]);

	free(string);
	free(argv);
	exit(status);
}

/**
*extract_path - function to retrieve the value of the path env
*@envarray: pointer to array
*Return: integer
*/

char extract_path(char **envarray)
{
	size_t envIndex = 0, index = 0, pathLen = 5;

	char *path = NULL;

	for (envIndex = 0; str_cmp(envarray[envIndex], "PATH=", 5); envIndex++)
		;
	if (envarray[envIndex] == NULL)
	return (NULL);

	for (pathLen = 5; envarray[envIndex][index]; index++, pathLen++)
		;
	path = malloc(sizeof(char) * (pathLen + 1));

	if (path == NULL)
		return (NULL);

	for (index = 5, pathLen = 0; envarray[envIndex][index]; index++, pathLen++)
		path[pathLen] = envarray[envIndex][index];

	path[pathLen] = '\0';
	return (path);
}
