#include <unistd.h>
#include <stdarg.h>
#include "main.h"
#include <stdio.h>

/**
  *_printf - produces output according to a format
  *@format: is a character string
  *
  *Return: returns number of bytes
  */

int _printf(const char *format, ...)
{
	int count = 0;
	va_list args;

	va_start(args, format);

	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			if (*format == '%')
			{
				_putc('%');
			}
			else if (*format == 'c')
			{
				_putc(va_arg(args, int));
			}
			else if (*format == 's')
			{
				fputs(va_arg(args, const char *), stdout);
			}
		}
		else
		{
			_putc(*format);
		}
		format++;
		count++;
	}
	return (count);
}
