#include "headers.h"

/**
 * _strlen - measures length of string.
 * @s: pointer to the chars string.
 *
 * Return: length of chars string.
 */
int _strlen(const char *s)
{
	int length = 0;

	if (!s)
		return (length);
	for (length = 0; s[length]; length++)
		;
	return (length);
}

/**
 * _strcat - Concants two strings.
 * @dest: pointer to destination string.
 * @src: pointer to source string.
 *
 * Return: pointer to destination string.
 */
char *_strcat(char *dest, const char *src)
{
	char *destTemp;
	const char *srcTemp;

	destTemp = dest;
	srcTemp =  src;

	while (*destTemp != '\0')
		destTemp++;

	while (*srcTemp != '\0')
		*destTemp++ = *srcTemp++;
	*destTemp = '\0';
	return (dest);
}

/**
 * _strcpy - copies string pointed to by src
 *		to the buff pointed by des.
 * @dest: pointer to the destination of copied string.
 * @src: pointer to the source string.
 *
 * Return: pointer to dest.
 */
char *_strcpy(char *dest, const char *src)
{
	size_t i;

	for (i = 0; src[i] != '\0'; i++)
		dest[i] = src[i];
	dest[i] = '\0';
	return (dest);
}

/**
 * _strncat - concants 2 strings where nbytes
 *		are copied from source.
 * @dest: pointer to destination string.
 * @src: pointer to source string.
 * @n: bytes to copy from src.
 *
 * Return: pointer to destination string.
 */
char *_strncat(char *dest, const char *src, size_t n)
{
	size_t dest_len = _strlen(dest);
	size_t i;

	for (i = 0; i < n && src[i] != '\0'; i++)
		dest[dest_len + i] = src[i];
	dest[dest_len + i] = '\0';

	return (dest);
}

/**
 * _strncmp - Compares 2 strings.
 * @s1: pointer to string 1.
 * @s2: pointer to string 2.
 * @n: The first n bytes of strings to compare.
 *
 * Return: Less than 0 if s1 is < s2.
 *         0 if s1 = s2 match.
 *         Greater than 0 if s1 > s2.
 */
int _strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i;

	for (i = 0; s1[i] && s2[i] && i < n; i++)
	{
		if (s1[i] > s2[i])
			return (s1[i] - s2[i]);
		else if (s1[i] < s2[i])
			return (s1[i] - s2[i]);
	}
	if (i == n)
		return (0);
	else
		return (-15);
}
