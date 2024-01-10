#include "main.h"


/**
 * oct_spec - Handles the %o specifier
 * @king: Arguments
 *
 * Return: Integer
 */
int oct_spec(va_list king)
{
	unsigned int octa_king = va_arg(king, unsigned int);

	return (print_oct(octa_king));
}

/**
 * print_oct - Prints octal numbers
 * @v: The number to convert
 *
 * Return: len
 */
int print_oct(unsigned int v)
{
	int len = 0, x = 0, y;
	char king_oct[32];

	if (v == 0)
	{
		len += print_character('0');
	}

	while (v > 0)
	{
		king_oct[x] = (v % 8) + '0';
		v /= 8;
		x++;
	}

	y = x - 1;
	while (y >= 0)
	{
		len += print_character(king_oct[y]);
		y--;
	}
	return (len);
}
