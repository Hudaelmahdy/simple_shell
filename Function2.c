#include "shell.h"

/**
*get_env - get the value of enviromental variable
*@envarray: name of array
*Return: 0
*/

void get_env(char **envarray)
{
	size_t index = 0;

	while (envarray[index])
	{
		write(STDOUT_FILENO, envarray[index], str_len(envarray[index]));
		write(STDOUT_FILENO, "\n", 1);
		index++;
	}
}



/**
*user_input - function to read al line of input from the user
*Return: input for user
*/

char *user_input(void)
{
	size_t inputSize = 0;
	char *string = NULL;

	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "$", 2);

	if (getline(&string, &inputSize, stdin) == -1)
	{
		free(string);
		return (NULL);
	}
	return (string);
}

/**
*evaluate_path - check command provided in argv
*@argv: command input
*@envarray: enviroment
*Return:pointer of str
*/

int evaluate_path(char **argv, char **envarray)
{
	char *dirToken = NULL, *pathValue = NULL, *fullPath = NULL;
	size_t dir_len, cmd_len;
	struct stat command_stat;

	if (stat(*argv, &command_stat) == 0)
	{
		return (-1);
	}
pathValue = extract_path(envarray);
	if (!pathValue)
		return (-1);
	dirToken = _strtok(pathValue, ":");
	cmd_len = str_len(*argv);
	while (dirToken)
	{
		dir_len = str_len(dirToken);
		fullPath = malloc(sizeof(char) * (dir_len + cmd_len + 2));
		if (!fullPath)
		{
			free(pathValue);
			return (-1);
		}
		fullPath = str_cpy(fullPath, dirToken);
		str_cat(fullPath, "/");
		str_cat(fullPath, *argv);

		if (stat(fullPath, &command_stat) == 0)
		{
			*argv = fullPath;
			free(pathValue);
			return (0);
		}
		free(fullPath);
		dirToken = _strtok(NULL, ":");
	}
	free(pathValue);
	return (-1);
}
