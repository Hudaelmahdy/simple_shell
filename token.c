#include "shell.h"

/**
 * tokening - function to split and create full string command
 * @str: delimiter for strtok
 * @buffer: input string pointer
 * Return: string with full command.
*/

char **tokening(char *buffer, const char *str)
{
	char *token = NULL, **commands = NULL;
	size_t bufsize = 0;
	int i = 0;

	if (buffer == NULL)
		return (NULL);
	bufsize = strlen(buffer);
	commands = malloc((bufsize + 1) * sizeof(char *));
	if (commands == NULL)
	{
		perror("Memory allocation failed");
		free(buffer);
		free_double_pointer(commands);
		exit(EXIT_FAILURE);
	}
	token = strtok(buffer, str);
	while (token != NULL)
	{
		commands[i] = malloc(strlen(token) + 1);
		if (commands[i] == NULL)
		{
			perror("Memory allocation failed");
			free_double_pointer(commands);
			return (NULL);
		}
		strcpy(commands[i], token);
		token = strtok(NULL, str);
		i++;
	}
	commands[i] = NULL;
	return (commands);
}
