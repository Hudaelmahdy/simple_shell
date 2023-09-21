#include "shell.h"

/**
 * get_token - function to get token of string
 * @string: command user.
 * Return: pointer
*/

char **get_token(char *string)
{
	char **user_command = NULL;
	char *token = NULL;
	size_t i = 0;
	int size = 0;

	if (string == NULL)
	{
		return (NULL);
	}
	for (i = 0; string[i]; i++)
	{
		if (string[i] == ' ')
		{
			size++;
		}
	}
	if ((size + 1) == str_len(string))
	{
		return (NULL);
	}
	user_command = malloc(sizeof(char *) * (size + 2));
	if (user_command == NULL)
	{
		return (NULL);
	}
	token = _strtok(string, " \n\t\r");
	for (i = 0; token != NULL; i++)
	{
		user_command[i] = token;
		token = _strtok(NULL, " \n\t\r");
	}
	user_command[i] = NULL;
	return (user_command);
}

/**
 * fork_function - creates a fork
 * @argv: value path and command
 * @args: name of program
 * @envarray: environment
 * @string: command line
 * @nproc: id of proccess
 * @cnt: check new test
 * Return: 0
*/
int fork_function(char **argv, char **args, char **envarray,
char *string, int nproc, int cnt)
{
	pid_t child;
	int status;
	char *form = "%s: %d: %s: not found\n";

	if (child == 0)
	{
		if (execve(argv[0], argv, envarray) == -1)
		{
			fprintf(stderr, form, args[0], nproc, argv[0]);
			if (!cnt)
			{
				free(argv);
				free(string);
				exit(errno);
			}
		}
	}
		else
		{
			wait(&status);
			if (WIFEXITED(status) && WEXITSTATUS(status) != 0)
			{
				return (WEXITSTATUS(status));
			}
	}
	return (0);
}
