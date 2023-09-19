#include "main.h"
/**
 * print_char - Prints a character
 * @list: arg lists
 * Return: return number of bytes
 */
int print_char(va_list list)
{
	_putc(va_arg(list, int));
	return (1);
}

/**
 * print_string - Prints a string
 * @list: arg lists
 * Return: number of bytes
 */
int print_string(va_list list)
{
	int s;
	char *str;

	str = va_arg(list, char *);
	if (str == NULL)
		str = "(null)";
	for (s = 0; str[s] != '\0'; s++)
		_putc(str[s]);
	return (s);
}

/**
 * print_percent - Prints %
 * @list: arg lists
 * Return: number of bytes
 */
int print_percent(__attribute__((unused))va_list list)
{
	_putc('%');
	return (1);
}

/**
 * print_integer - Prints an integer
 * @list: arg lists
 * Return: return number of bytes
 */
int print_integer(va_list list)
{
	int n;

	n = print_number(list);
	return (n);
}

/**
 * unsigned_integer - Prints Unsigned integers
 * @list: arg lists
 * Return: number counts
 */
int unsigned_integer(va_list list)
{
	unsigned int num;

	num = va_arg(list, unsigned int);

	if (num == 0)
		return (print_unsgined_number(num));

	if (num < 1)
		return (-1);
	return (print_unsgined_number(num));
}
