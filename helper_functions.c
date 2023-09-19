#include "main.h"
#include <stdio.h>

/**
 * rev_string - reverses a string in place
 *
 * @s: string to reverse
 * Return: A pointer to a character
 */
char *rev_string(char *s)
{
	int len;
	int head;
	char tmp;
	char *dest;

	for (len = 0; s[len] != '\0'; len++)
	{}

	dest = malloc(sizeof(char) * len + 1);
	if (dest == NULL)
		return (NULL);

	_memcpy(dest, s, len);
	for (head = 0; head < len; head++, len--)
	{
		tmp = dest[len - 1];
		dest[len - 1] = dest[head];
		dest[head] = tmp;
	}
	return (dest);
}

/**
 * write_base - sends characters to be written on standard output
 * @str: String to parse
 */
void write_base(char *str)
{
	int c;

	for (c = 0; str[c] != '\0'; c++)
		_putc(str[c]);
}

/**
 * base_len - Calculates length of an octal number
 * @num: The number for which the length is being calculated
 * @base: Base use for calculation
 * Return: An integer representing the length of a number
 */
unsigned int base_len(unsigned int num, int base)
{
	unsigned int oc;

	for (oc = 0; num > 0; oc++)
	{
		num = num / base;
	}
	return (oc);
}

/**
 * _memcpy - copy memory area
 * @dest: Destination for copying
 * @src: Source to copy from
 * @n: The number of bytes to copy
 * Return: The _memcpy() function returns a pointer to dest.
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int c;

	for (c = 0; c < n; c++)
		dest[c] = src[c];
	dest[c] = '\0';
	return (dest);
}
