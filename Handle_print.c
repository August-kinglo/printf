#include "main.h"

/**
 * handle_format - Handles and prints formatted arguments
 * @format_string: Formatted string containing the arguments
 * @index: Current index in the format string
 * @args_list: List of arguments to be printed
 * @output_buffer: Buffer for output handling
 * @active_flags: Calculated active flags
 * @field_width: Calculated field width
 * @precision: Precision specification
 * @size_spec: Size specifier
 * Return: Number of characters printed or -1 on error
 */
int handle_format(const char *format_string, int *index, va_list args_list,
                   char output_buffer[], int active_flags, int field_width,
                   int precision, int size_spec)
{
	int i, unknown_length = 0, printed_chars = -1;
	FormatType format_types[] = {
		{'c', print_character}, {'s', print_string}, {'%', print_percent},
		{'i', print_integer}, {'d', print_integer}, {'b', print_binary},
		{'u', print_unsigned}, {'o', print_octal}, {'x', print_hex_lower},
		{'X', print_hex_upper}, {'p', print_pointer}, {'S', print_non_printable},
		{'r', print_reverse}, {'R', print_rot13}, {'\0', NULL}
	};

	for (i = 0; format_types[i].format != '\0'; i++) {
		if (format_string[*index] == format_types[i].format) {
			return format_types[i].function(args_list, output_buffer,
							active_flags, field_width,
							precision, size_spec);
		}
	}

	if (format_types[i].format == '\0') {
		if (format_string[*index] == '\0') {
			return (-1);
		}
		unknown_length += write(1, "%", 1);
		if (format_string[*index - 1] == ' ') {
			unknown_length += write(1, " ", 1);
		} else if (field_width) {
			--(*index);
			while (format_string[*index] != ' ' &&
			       format_string[*index] != '%') {
				--(*index);
			}
			if (format_string[*index] == ' ') {
				--(*index);
			}
			return (1);
		}
		unknown_length += write(1, &format_string[*index], 1);
		return (unknown_length);
	}

	return (printed_chars);
}
