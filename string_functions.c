#include "shell.h"

/**
 * str_len - function to print the length of the string
 * @s: input string
 * Return: length of the string
*/

int str_len(char *s)
{
	int length = 0;

		while (*(s + length) != '\0')
			length++;
		return (length);
}


/**
 * str_cmp - function to compare two strings
 * @s1: first string
 * @s2: second string
 * Return: comparesion
*/

int str_cmp(char *s1, char *s2)
{
	int i;

	for (i = 0; s1[i] != '\0' && s2[i] != '\0'; i++)
	{
		if (s1[i] != s2[i])
		{
			return ((int)s1[i] - s2[i]);
		}
	}
	return (0);
}


/**
 * str_cmp - function that compares two strings
 * @s1: 1st string
 * @s2: 2nd string
 * @n:number of characters
 * Return: comparesion
*/

size_t str_cmp(char *s1, char *s2, size_t n)
{
		size_t k, j;

		for (j = 0; s1[j] != '\0' && j < n; j++)
		{
			k = s1[j] - s2[j];

			if (k != 0)
			{
				return (k);
			}
		}
		return (0);
}


/**
 * str_cpy - copying the string from src to dest
 * @dest: destination
 * @src: source of copy
 * Return: pointer of destination
*/

char str_cpy(char *dest, char *src)
{
	int i = 0;

	while (*(src + i) != '\0')
	{
		*(dest + i) = *(src + i);
		++i;
	}
	*(dest + i) = *(src + i);
	return (dest);
}

/**
 * str_cat - concenates te strings
 * @dest: destination
 * @src: source
 * Return: destination
*/

char *str_cat(char *dest, char *src)
{
	int des = 0;
	int sour = 0;

	while (dest[des] != '\0')
	{
		des++;
	}
	while (src[sour] != '\0')
	{
		dest[des] = src[sour];
		des++;
		sour++;
	}
	dest[des] = '\0';
	return (dest);
}
