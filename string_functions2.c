#include "shell.h"

char *_strchr(const char *s, int c);
size_t _strspn(const char *s1, const char *s2);
size_t _strcspn(const char *s1, const char *s2);

/**
 * _strtok - breaks string into token and delimiter chars at beginning
 * @str: string that tokinize
 * @separator: string with char that delimitering string
 * Return: 1st and 2nd token
*/
char *_strtok(char *str, const char *separator)
{
	static char *next_dir;

	if (str)
	{
		next_dir = str;
	}
	else if (!next_dir)
	{
		return (0);
	}
	str = next_dir + _strspn(next_dir, separator);
	next_dir = str + _strcspn(str, separator);
	if (next_dir == str)
	{
		return (next_dir = 0);
	}
	next_dir = *next_dir ? *next_dir = 0, next_dir + 1 : 0;
	return (str);
}

/**
 * _strcspn - computing length of max sigment of the string
 * @s1: string that will compute the length
 * @s2: deliminator
 * Return: length if sigment
*/
size_t _strcspn(const char *s1, const char *s2)
{
	size_t r = 0;

	while (*s1)
	{
		if (_strchr(s2, *s1))
		{
			return (r);
		}
		s1++, r++;
	}
	return (r);
}


/**
 * _strspn - computing length of max sigment of the str
 * @s1: string that will compute the length
 * @s2: deliminator
 * Return: length of sigment
*/
size_t _strspn(const char *s1, const char *s2)
{
	size_t r = 0;

	while (*s1 && _strchr(s2, *s1++))
	{
		r++;
	}
	return (r);
}


/**
 * _strchr - locating the 1st occurrence of char
 * @s: string
 * @c: character
 * Return: pointer of located char or null
*/

char *_strchr(const char *s, int c)
{
	while (*s != (char)c)
	{
		if (!*s++)
		{
			return (0);
		}
	}
	return ((char *)s);
}
