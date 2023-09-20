#include "shell.h"

/**
*exit_shell - function to exit shell
*@argv: array
*/

void exit_shell(char **argv, char **envarray)
{
	int i, n;

	(void)envarray;

	if (argv[1])
	{
		n = _atoi(argv[1]);
			if (n <= -1)
				n = 2;
			freeargv(argv);
			exit(n);
	}
	for (i = 0; argv[i]; i++)
		free(argv[i]);
	free(argv);
	exit(0);
}

/**
*_atoi - convert string to integer
*@string: pointer to string
*Return: integer
*/

int _atoi(char *string)
{
	int i, integer, sign = 1;

	i = 0;

	integer = 0;
	while (!((string[i] >= '0') && (string[i] <= '9')) && (string[i] != '\0'))
	{
		if (string[i] == '-')
		{
			sign = sign * (-1);
		}
		i++;
	}
	while ((string[i] >= '0') && (string[i] <= '9'))
	{
		integer = (integer * 10) + (sign * (string[i] - '0'));
		i++;
	}
	return (integer);
}

/**
*print_env - prints the environment
*envarray - store the value printed by the function
*@argv: arguments
*/


void print_env(char **argv __attribute__ ((unused)), char **envarray)
{
	int i;

	for (i = 0; envarray[i]; i++)
	{
		_puts(envarray[i]);
		_puts("\n");
	}
}

/**
*set_env - set new enviroment
*@argv: arguments
*/

void set_env(char **argv, char **envarray)
{
	int i, j, k;

	if (!argv[1] || !argv[2])
	{
		perror(get_env("_", envarray));
		return;
	}
	for (i = 0; envarray[i]; i++)
	{
		j = 0;
		if (argv[1][j] == envarray[i][j])
		{
			while (argv[1][j])
			{
				if (argv[1][j] != envarray[i][j])
					break;
				j++;
			}
			if (argv[i][j] == '\0')
			{
				k = 0;
				while (argv[2][k])
				{
					envarray[i][j + 1 + k] = argv[2][k];
					k++;
				}
				envarray[i][j + 1 + k] = '\0';
				return;
			}
		}
	}
if (!envarray[i])
	{
	envarray[i] = concat(argv[1], "=", argv[2]);
	envarray[i + 1] = '\0';
	}
}


/**
*unset_env - remove an enviroment
*@argv: arguments
*/

void unset_env(char **argv, char **envarray)
{
	int i, j;

	if (!argv[1])
	{
		perror(get_env("_", envarray));
		return;
	}
	for (i = 0; envarray[i]; i++)
	{
		j = 0;
		if (argv[1][j] == envarray[i][j])
		{
			while (argv[1][j])
			{
				if (argv[1][j] != envarray[i][j])
					break;
				j++;
			}
			if (argv[1][j] == '\0')
			{
				free(envarray[i]);
				envarray[i] = envarray[i + 1];
				while (envarray[i])
				{
					envarray[i] = envarray[i + 1];
					i++;
				}
				return;
			}
		}
	}
}
