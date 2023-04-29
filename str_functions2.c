#include "headers.h"

/**
 * _strcmp - compares two strings.
 * @s1: 1st string to be compared.
 * @s2: 2nd string
 *
 * Return: +ve byte diff if s1 > s2
 *         0 if s1 = s2
 *         -ve byte diff if s1 < s2
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}

	if (*s1 != *s2)
		return (*s1 - *s2);

	return (0);
}

/**
 * _strchr - locates a char in a string.
 * @s: string to be searched.
 * @c: char to be located.
 *
 * Return: If char is found -  pointer to 1st occurence.
 *         If char is not found - NULL.
 */
char *_strchr(char *s, char c)
{
	int index;

	for (index = 0; s[index]; index++)
	{
		if (s[index] == c)
			return (s + index);
	}

	return (NULL);
}

/**
 * _strspn - finds length of prefix substring.
 * @s: string to be searched.
 * @accept: prefix to be measured.
 *
 * Return: num of bytes in s which
 *         consist only of bytes from accept.
 */
int _strspn(char *s, char *accept)
{
	int bytes = 0;
	int i;

	while (*s)
	{
		for (i = 0; accept[i]; i++)
		{
			if (*s == accept[i])
			{
				bytes++;
				break;
			}
		}
		s++;
	}
	return (bytes);
}

