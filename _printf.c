#include "main.h"

void flush_buffer(char buffer[], int *buff_index);

/**
 * my_printf - Custom printf function
 * @format: Format string.
 * Return: Number of printed characters.
 */
int my_printf(const char *format, ...)
{
	int i, total_printed = 0, current_printed = 0;
	int flags, width, precision, size, buffer_index = 0;
	va_list args;
	char output_buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(args, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			output_buffer[buffer_index++] = format[i];
			if (buffer_index == BUFF_SIZE)
				flush_buffer(output_buffer, &buffer_index);
			current_printed++;
		}
		else
		{
			flush_buffer(output_buffer, &buffer_index);
			flags = calculate_flags(format, &i);
			width = calculate_width(format, &i, args);
			precision = calculate_precision(format, &i, args);
			size = calculate_size(format, &i);
			i++;
			current_printed = handle_output(format, &i, args, output_buffer,
				flags, width, precision, size);
			if (current_printed == -1)
				return (-1);
			total_printed += current_printed;
		}
	}

	flush_buffer(output_buffer, &buffer_index);

	va_end(args);

	return (total_printed);
}

/**
 * flush_buffer - Prints the contents of the buffer if it's not empty
 * @buffer: Array of characters
 * @buff_index: Current index in the buffer.
 */
void flush_buffer(char buffer[], int *buff_index)
{
	if (*buff_index > 0)
		write(1, &buffer[0], *buff_index);

	*buff_index = 0;
}
