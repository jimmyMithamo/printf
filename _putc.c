#include <unistd.h>

/**
 * _putc - writes c to stdout
 * @c: character to print
 *
 * Return: 1 successfully,
 * On error, -1 is returned.
 */

int _putc(char c)
{
        return (write(1, &c, 1));
}