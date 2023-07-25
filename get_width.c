#include "main.h"

/**
 * get_width - Calculates the width for printing
 * @format: Formatted string in which to print the arguments.
 * @i: List of arguments to be printed.
 * @list: list of arguments.
 *
 * Return: width.
 */
int get_width(const char *format, int *i, va_list list)
{
	int aliso_i;
	int width = 0;

	for (aliso_i = *i + 1; format[aliso_i] != '\0'; aliso_i++)
	{
		if (is_digit(format[aliso_i]))
		{
			width *= 10;
			width += format[aliso_i] - '0';
		}
		else if (format[aliso_i] == '*')
		{
			aliso_i++;
			width = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = aliso_i - 1;

	return (width);
}
