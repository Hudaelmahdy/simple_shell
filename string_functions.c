#include "shell.h"

/**
 * _strlen - function to print the length of the string
 * @string: input string
 * Return: length of the string
*/

int _strlen(char *string)
{
	int length = 0;

		while (*(string + length) != '\0')
			length++;
		return (length);
}


/**
 * _strdup - returning tha pointer to new allocated space in memory
 * @str: pointer of string
 * Return: str
*/

char *_strdup(char *str)
{
	int i, j;
	char *new;

	if (!str)
	{
		return (NULL);
	}
	for (j = 0; str[j] != '\0';)
	{
		j++;
	}
	new = malloc(sizeof(char) * j + 1);
	if (!new)
	{
		return (NULL);
	}
	for (i = 0; i < j; i++)
	{
		new[i] = str[i];
	}
	new[j] = str[j];
	return (new);
}


/**
 * concat - function that concatenates three strings
 * @name: input string
 * @sep: input string
 * @value:input string
 * Return: result string pointer
*/

char *concat(char *name, char *sep, char *value)
{
		char *res;
		int i1, i2, i3, j, k;

		i1 = _strlen(name);
		i2 = _strlen(sep);
		i3 = _strlen(value);

		res = malloc(i1 + i2 + i3 + 1);
		if (!res)
		{
			return (NULL);
		}
		for (j = 0; name[j]; j++)
		{
			res[j] = name[j];
		}
		k = j;
		for (j = 0; sep[j]; j++)
		{
			res[k + j] = sep[j];
		}
		k = k + j;
		for (j = 0; value[j]; j++)
		{
			res[k + j] = value[j];
		}
		k = k + j;
		res[k] = '\0';
		return (res);
}


/**
 * _putchar - typing character c to stdout
 * @c: character
 * Return: 1 on success, -1 on failed
*/

int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _puts - print the string
 * @str: string
*/

void _puts(char *str)
{
	int i = 0;

	while (str[i])
	{
		_putchar(str[i]);
		i++;
	}
}
