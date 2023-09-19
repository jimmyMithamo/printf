#include "main.h"

/**
 * print_number - prints a number 
 * @args: arg lists
 * Return: number of bytes
 */
int print_number(va_list args)
{
	int i;
	int d;
	int len;
	unsigned int num;

	i  = va_arg(args, int);
	d = 1;
	len = 0;

	if (i < 0)
	{
		len += _putc('-');
		num = n * -1;
	}
	else
		num = i;

	for (; num / div > 9; )
		div *= 10;

	for (; d != 0; )
	{
		len += _putc('0' + num / div);
		num %= div;
		d /= 10;
	}

	return (len);
}
/**
 * print_unsgined_number - Prints an unsigned number
 * @n: unsigned integer to be printed
 * Return: The amount of numbers printed
 */
int print_unsgined_number(unsigned int n)
{
	int d;
	int len;
	unsigned int num;

	d = 1;
	len = 0;

	num = n;

	for (; num / d > 9; )
		d *= 10;

	for (; d != 0; )
	{
		len += _putc('0' + num / d);
		num %= d;
		d /= 10;
	}

	return (len);
}
