#include "main.h"

/**
 * parser - Receives the main string and all the necessary parameters to
 * print a formated string.
 * @format: A string containing all the desired characters.
 * @f_list: A list of all the posible functions.
 * @arg_list: A list containing all the argumentents passed to the program.
 * Return: A total count of the characters printed.
 */
int parser(const char *format, conver_t f_list[], va_list arg_list)
{
	int c, b, r_val, printed_chars;

	printed_chars = 0;
	for (c = 0; format[c] != '\0'; c++)/* Iterates through the main str*/
	{
		if (format[c] == '%') /*Checks for format specifiers*/
		{
			/*Iterates through struct to find the right func*/
			for (b = 0; f_list[b].sym != NULL; b++)
			{
				if (format[c + 1] == f_list[b].sym[0])
				{
					r_val = f_list[b].f(arg_list);
					if (r_val == -1)
						return (-1);
					printed_chars += r_val;
					break;
				}
			}
			if (f_list[b].sym == NULL && format[c + 1] != ' ')
			{
				if (format[c + 1] != '\0')
				{
					_putc(format[c]);
					_putc(format[c + 1]);
					printed_chars = printed_chars + 2;
				}
				else
					return (-1);
			}
			c = c + 1; /*Updating c to skip format symbols*/
		}
		else
		{
			_putc(format[c]); /*call the write function*/
			printed_chars++;
		}
	}
	return (printed_chars);
}
