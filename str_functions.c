#include "shell.h"

/**
 *_strlen - Count the number of characters
 *@string: String for to count
 *Return: Number of characters
 */
int _strlen(const char *string)
{
	int len = 0;

	while (string[len])
		len++;
	return (len);
}

/**
 * _strcmp - compares two strings
 * @s1: string one
 * @s2: string two
 * Return: 0 if equal or difference between s1 and s2
 */
int _strcmp(char *s1, char *s2)
{
	int i = 0;

	for (; s1[i] && s2[i]; i++)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
	}

	return (s1[i] - s2[i]);
}

/**
 * *_strcpy - copy string
 *@dest: new string
 *@src: origin string
 *@*src: value string
 *@*dest: value new string
 *Return: dest
 */
char *_strcpy(char *dest, char *src)
{
	int i;

	for (i = 0 ; src[i] != '\0' ; i++)
		dest[i] = src[i];
	if (src[i] == '\0')
		dest[i] = '\0';
	return (dest);
}

/**
 *_strncmp - Compare the numbers of bytes of two strings
 *@s1: string one.
 *@s2: string two.
 *@n: Numbers of bytes.
 *Return: 0 if is exit success or one number if is failed.
 */
int _strncmp(char *s1, char *s2, size_t n)
{
	size_t i = 0;

	for (; (s1[i] && s2[i]) && i < n; i++)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
	}
	return (s1[i] - s2[i]);
}

/**
 * *_strcat - concatenar
 *@dest: dest string
 *@src: source string
 *Return: dest string
 */
char *_strcat(char *dest, char *src)
{
	int i, j;

	for (i = 0 ; dest[i] != '\0' ; i++)
	;
	for (j = 0 ; (dest[i + j] = *src++) != '\0' ; j++)
	;
	return (dest);
}
