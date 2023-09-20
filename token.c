#include "shell.h"

/**
 * tokiniz - function to split and create full string command
 * @separator: delimiter.
 * @str: splited string.
 * Return: string with full command.
*/

char **tokenizeString(char *str, const char *separator)
{
	int index, wordcount;
	char **tokenArray;
	char *token;
	char *cpstring;

	cpstring = malloc(_strlen(str) + 1);
	if (cpstring == NULL)
	{
		perror(get_env("_"));
		return (NULL);
	}
	index = 0;
	while (str[index])
	{
		cpstring[index] = str[index];
		index++;
	}
	cpstring[index] = '\0';
	token = strtok(cpstring, separator);
	tokenArray = malloc((sizeof(char *) * 2));
	tokenArray[0] = _strdup(token);
	index = 1;
	wordcount = 3;
	while (token)
	{
		token = strtok(NULL, separator);
		tokenArray = _reallocate(tokenArray, (sizeof(char *) * (wordcount - 1)),
		(sizeof(char *) * wordcount));
		tokenArray[index] = _strdup(token);
		index++;
		wordcount++;
	}
	free(cpstring);
	return (tokenArray);
}
