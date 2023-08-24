#include "main.h"

/**
 * calculate_width - Determines the width for formatting
 * @format: Format string to analyze for width
 * @index: Current index in the format string
 * @args: Variable argument list
 * Return: Calculated width
 */
int calculate_width(const char *format, int *index, va_list args)
{
	int current_index;
	int width = 0;

	for (current_index = *index + 1; format[current_index] != '\0'; current_index++)
	{
		if (is_digit(format[current_index]))
		{
			width *= 10;
			width += format[current_index] - '0';
		}
		else if (format[current_index] == '*')
		{
			current_index++;
			width = va_arg(args, int);
			break;
		}
		else
		{
			break;
		}
	}

	*index = current_index - 1;

	return width;
}
