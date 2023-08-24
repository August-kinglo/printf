#include <stdio.h>
#include "main.h"

/**
 * is_printable_character - Checks if a character is printable
 * @c: Character to be checked.
 *
 * Return: 1 if c is printable, 0 otherwise.
 */
int is_printable_character(char c)
{
    return (c >= 32 && c < 127);
}

/**
 * append_hexadecimal_code - Appends ASCII in hexadecimal code to buffer
 * @buffer: Array of characters.
 * @index: Index at which to start appending.
 * @ascii_code: ASCII code to be appended.
 * Return: Always 3.
 */
int append_hexadecimal_code(char ascii_code, char buffer[], int index)
{
    const char hex_map[] = "0123456789ABCDEF";

    if (ascii_code < 0)
        ascii_code *= -1;

    buffer[index++] = '\\';
    buffer[index++] = 'x';
    buffer[index++] = hex_map[ascii_code / 16];
    buffer[index] = hex_map[ascii_code % 16];

    return 3;
}

/**
 * is_decimal_digit - Checks if a character is a decimal digit
 * @c: Character to be checked.
 *
 * Return: 1 if c is a decimal digit, 0 otherwise.
 */
int is_decimal_digit(char c)
{
    return (c >= '0' && c <= '9');
}

/**
 * convert_to_size - Converts a number to the specified size
 * @num: Number to be converted.
 * @size: Size specifier for the conversion.
 *
 * Return: Converted value of num.
 */
long int convert_to_size(long int num, int size)
{
    if (size == SIZE_LONG)
        return num;
    else if (size == SIZE_SHORT)
        return (short)num;

    return (int)num;
}

/**
 * convert_unsigned_to_size - Converts an unsigned number to the specified size
 * @num: Number to be converted.
 * @size: Size specifier for the conversion.
 *
 * Return: Converted value of num.
 */
unsigned long int convert_unsigned_to_size(unsigned long int num, int size)
{
    if (size == SIZE_LONG)
        return num;
    else if (size == SIZE_SHORT)
        return (unsigned short)num;

    return (unsigned int)num;
}

int main(void)
{
    char printable = 'A';
    printf("Is printable? %d\n", is_printable_character(printable));

    char buffer[10];
    int index = 0;
    int appended = append_hexadecimal_code(65, buffer, index);
    printf("Appended: %d\n", appended);

    printf("Is decimal digit? %d\n", is_decimal_digit('7'));

    long int num = 100;
    int size_code = SIZE_SHORT;
    long int converted = convert_to_size(num, size_code);
    printf("Converted: %ld\n", converted);

    unsigned long int unsigned_num = 200;
    size_code = SIZE_LONG;
    unsigned long int converted_unsigned = convert_unsigned_to_size(unsigned_num, size_code);
    printf("Converted unsigned: %lu\n", converted_unsigned);

    return 0;
}
