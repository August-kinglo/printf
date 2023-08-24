#include "main.h"

/**
 * parse_flags - Parses and calculates active flags
 * @format: Formatted string to analyze for flags
 * @index: Index to start parsing from
 * Return: Active flags
 */
int parse_flags(const char *format, int *index)
{
	// Flag characters: - + 0 # ' '
	const char FLAG_CHARS[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAG_VALUES[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	int flags = 0;
	int current_index;

	for (current_index = *index + 1; format[current_index] != '\0'; current_index++)
	{
		int flag_found = 0;

		for (int j = 0; FLAG_CHARS[j] != '\0'; j++)
		{
			if (format[current_index] == FLAG_CHARS[j])
			{
				flags |= FLAG_VALUES[j];
				flag_found = 1;
				break;
			}
		}

		if (!flag_found)
			break;
	}

	*index = current_index - 1;

	return flags;
}
