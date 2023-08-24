#include <stdio.h>
#include "main.h"

/**
 * determine_size - Determines the size based on the format
 * @format: Formatted string in which to print the arguments
 * @i: Index of the format string
 *
 * Return: Size code.
 */
int determine_size(const char *format, int *i)
{
    int curr_i = *i + 1;
    int size_code = 0;

    if (format[curr_i] == 'l')
        size_code = SIZE_LONG;
    else if (format[curr_i] == 'h')
        size_code = SIZE_SHORT;

    if (size_code == 0)
        *i = curr_i - 1;
    else
        *i = curr_i;

    return size_code;
}

int main(void)
{
    int i = 0;
    int size_code = determine_size("The size is l\n", &i);
    printf("Size code: %d\n", size_code);

    size_code = determine_size("The size is h\n", &i);
    printf("Size code: %d\n", size_code);

    size_code = determine_size("The size is normal\n", &i);
    printf("Size code: %d\n", size_code);

    return 0;
}
