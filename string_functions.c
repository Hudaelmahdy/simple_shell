#include "shell.h"

/**
 * str_len - function to print the length of the string
 * @str: input string
 * Return: length of the string
*/

unsigned int str_len(char *str)
{
		unsigned int length = 0;

		while (str[length])
			length++;
		return (length);
}


/**
 * str_cmp - function to compare two strings
 * @str1: first string
 * @str2: second string
 * Return: 1 in same string, 0 if not
*/

int str_cmp(char *str1, char *str2)
{
		unsigned int i = 0;

		while (str1[i])
		{
			if (str1[i] != str2[i])
				return (0);
			i++;
		}
		return (1);

}

/**
 * str_cpy - function to copy string to another
 * @dest: pointer for copied string
 * @src: pointer for string copy for
 * Return: copied string
*/

char *str_cpy(char *dest, char *src)
{
		char *init_dest = dest;

		while (*src)
			*dest++ = *src++;
		*dest = '\0';
		return (init_dest);
}


/**
 * str_cat - function that concatenates two strings
 * @dest: input string
 * @src: input string
 * Return: result string pointer
*/

char *str_cat(char *dest, char  *src)
{
		char *original_dest = dest;

		while (*dest)
			dest++;
		*dest++ = '/';
		while (*src)
			*dest++ = *src++;
		return (original_dest);
}


/**
 * _atoi - function that converts string to integer
 * @str: input string
 * Return: conversion integer
*/

int _atoi(char *str)
{
		int sign = 1;
		unsigned int total = 0;
		char null = 0;

		if (str == NULL)
			return (0);
		while (*str)
		{
			if (*str == '-')
				sign *= -1;
			if (*str >= '0' && *str <= '9')
			{
				null = 1;
				total = total * 10 + (*str - '0');
			}
			else if (*str < '0' || *str > '9')
				if (null == 1)
					break;
			str++;
		if (sign < 0)
			total = (-1 * (total));
		}
	return (total);
}

