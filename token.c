#include "shell.h"

/**
 * tokenizeString - function to split and create full string command
 * @separator: delimiter.
 * @str: splited string.
 * Return: string with full command.
*/

char **tokenizeString(char *str, const char *separator)
{
	int index, C;
	char **tArray;
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
	tArray = malloc((sizeof(char *) * 2));
	tArray[0] = _strdup(token);
	index = 1;
	C = 3;
	while (token)
	{
		token = strtok(NULL, separator);
		tArray = re_alloc(tArray, (sizeof(char *) * (C - 1)), (sizeof(char *) * C));
		tArray[index] = _strdup(token);
		index++;
		C++;
	}
	free(cpstring);
	return (tArray);
}

/**
 * execute - to executs the commands
 * @args: arguments array
*/
void execute(char **args)
{
	int pid, exitStatus;

	if (!args || !args[0])
	{
		return;
	}
	pid = fork();
	if (pid == 0)
	{
		execve(args[0], args, env_array);
			perror(args[0]);
		exit(EXIT_FAILURE);
	}
	wait(&exitStatus);
}


/**
 * re_alloc - function that is reallocating memory
 * @oldmem: previous pointer
 * @currsize: the previous size of previous pointer
 * @reqsize: the newest size of pointer
 * Return: reqsize.
*/

void *re_alloc(void *oldmem, unsigned int currsize, unsigned int reqsize)
{
	char *required;
	char *current;
	unsigned int i;

	if (oldmem == NULL)
		return (malloc(reqsize));
	if (reqsize == currsize)
		return (oldmem);
	if (reqsize == 0 && oldmem != NULL)
	{
		free(oldmem);
		return (NULL);
	}
	required = malloc(reqsize);
	current = oldmem;
	if (required == NULL)
		return (NULL);
	if (reqsize > currsize)
	{
		for (i = 0; i < currsize; i++)
		{
			required[i] = current[i];
		}
		free(oldmem);
		for (i = currsize; i < reqsize; i++)
		{
			required[i] = '\0';
		}
	}
	if (reqsize < currsize)
	{
		for (i = 0; i < reqsize; i++)
		{
			required[i] = current[i];
		}
		free(oldmem);
	}
	return (required);
}

/**
 * freeargv - function that frees the array of argv
 * @argv: the array pointer
*/

void freeargv(char **argv)
{
	int i;

	for (i = 0; argv[i]; i++)
	{
		free(argv[i]);
	}
	free(argv);
}
