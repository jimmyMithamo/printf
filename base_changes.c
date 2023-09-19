#include "main.h"
#include <stdio.h>
int hex_check(int, char);

/**
 * print_binary - Converts a number from base 10 to binary
 * @list: arg lists
 * Return: The length of the printed number
 */
int print_binary(va_list list)
{
	unsigned int num;
	int b;
	int len;
	char *str;
	char *rev_str;

	num = va_arg(list, unsigned int);
	if (num == 0)
		return (_putc('0'));
	if (num < 1)
		return (-1);
	len = base_len(num, 2);
	str = malloc(sizeof(char) * len + 1);
	if (str == NULL)
		return (-1);

	for (b = 0; num > 0; b++)
	{
		if (num % 2 == 0)
			str[b] = '0';
		else
			str[b] = '1';
		num = num / 2;
	}
	str[b] = '\0';
	rev_str = rev_string(str);
	if (rev_str == NULL)
		return (-1);
	write_base(rev_str);
	free(str);
	free(rev_str);
	return (len);
}

/**
 * print_octal - Prints the numeric representation of a number in octal base
 * @list: args lists
 * Return: symbols printed to stdout
 */
int print_octal(va_list list)
{
	unsigned int num;
	int l;
	char *octal_rep;
	char *rev_str;

	num = va_arg(list, unsigned int);

	if (num == 0)
		return (_putc('0'));
	if (num < 1)
		return (-1);
	l = base_len(num, 8);

	octal_rep = malloc(sizeof(char) * l + 1);
	if (octal_rep == NULL)
		return (-1);
	for (l = 0; num > 0; l++)
	{
		octal_rep[l] = (num % 8) + 48;
		num = num / 8;

	}
	octal_rep[l] = '\0';
	rev_str = rev_string(octal_rep);
	if (rev_str == NULL)
		return (-1);

	write_base(rev_str);
	free(octal_rep);
	free(rev_str);
	return (l);
}

/**
 * print_hex - Prints a decimal number on base 16 in lowercase
 * @list: arg lists
 * Return: Number of characters printed
 */
int print_hex(va_list list)
{
	unsigned int num;
	int l;
	int rem_num;
	char *hex_rep;
	char *rev_hex;

	num = va_arg(list, unsigned int);

	if (num == 0)
		return (_putc('0'));
	if (num < 1)
		return (-1);
	l = base_len(num, 16);
	hex_rep = malloc(sizeof(char) * l + 1);
	if (hex_rep == NULL)
		return (-1);
	for (l = 0; num > 0; l++)
	{
		rem_num = num % 16;
		if (rem_num > 9)
		{
			rem_num = hex_check(rem_num, 'x');
			hex_rep[l] = rem_num;
		}
		else
			hex_rep[l] = rem_num + 48;
		num = num / 16;
	}
	hex_rep[l] = '\0';
	rev_hex = rev_string(hex_rep);
	if (rev_hex == NULL)
		return (-1);
	write_base(rev_hex);
	free(hex_rep);
	free(rev_hex);
	return (l);
}


/**
 * print_heX - Prints a decimal number on base 16 in Uppercase
 * @list: arg lists
 * Return: Number of characters printed
 */
int print_heX(va_list list)
{
	unsigned int num;
	int l;
	int rem_num;
	char *hex_rep;
	char *rev_hex;

	num = va_arg(list, unsigned int);

	if (num == 0)
		return (_putc('0'));
	if (num < 1)
		return (-1);
	l = base_len(num, 16);
	hex_rep = malloc(sizeof(char) * l + 1);
	if (hex_rep == NULL)
		return (-1);
	for (l = 0; num > 0; l++)
	{
		rem_num = num % 16;
		if (rem_num > 9)
		{
			rem_num = hex_check(rem_num, 'X');
			hex_rep[l] = rem_num;
		}
		else
			hex_rep[l] = rem_num + 48;
		num = num / 16;
	}
	hex_rep[l] = '\0';
	rev_hex = rev_string(hex_rep);
	if (rev_hex == NULL)
		return (-1);
	write_base(rev_hex);
	free(hex_rep);
	free(rev_hex);
	return (l);
}

/**
 * hex_check - prints Hexadecimal
 * @num: Number to convert into letter
 * @x: Tells which hex function is calling it
 * Return: returns Ascii value for a letter
 */
int hex_check(int num, char x)
{
	char *hex = "abcdef";
	char *Hex = "ABCDEF";

	num = num - 10;
	if (x == 'x')
		return (hex[num]);
	else
		return (Hex[num]);
	return (0);
}
