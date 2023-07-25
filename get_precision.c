#include "main.h"

/**
 * get_precision - Calculates the precision for printing
 * @format: Formatted string in which to print the arguments
 * @i: List of arguments to be printed.
 * @list: list of arguments.
 *
 * Return: Precision.
 */
int get_precision(const char *format, int *i, va_list list)
{
	int soon_i = *i + 1;
	int precision = -1;

	if (format[soon_i] != '.')
		return (precision);

	precision = 0;

	for (soon_i += 1; format[soon_i] != '\0'; soon_i++)
	{
		if (is_digit(format[soon_i]))
		{
			precision *= 10;
			precision += format[soon_i] - '0';
		}
		else if (format[soon_i] == '*')
		{
			soon_i++;
			precision = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = soon_i - 1;

	return (precision);
}

