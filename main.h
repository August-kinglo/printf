#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024

/* FLAGS */
#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

/* SIZES */
#define S_LONG 2
#define S_SHORT 1

/**
 * struct fmt - Struct op
 *
 * @fmt: The format.
 * @fn: The function associated.
 */
struct fmt
{
	char fmt;
	int (*fn)(va_list, char[], int, int, int, int);
};


/**
 * typedef struct fmt fmt_t - Struct op
 *
 * @fmt: The format.
 * @fm_t: The function associated.
 */
typedef struct fmt fmt_t;

int _printf(const char *format, ...);
int handle_print(const char *fmt, int *i,
va_list list, char buffer[], int flags, int width, int precision, int size);

/****************** FUNCTIONS ******************/

/* Funtions to print chars and strings */
int print_character(va_list args, char buffer[],
	int flags, int width, int precision, int size);
int print_custom_string(va_list args, char buffer[],
	int flags, int width, int precision, int size);
int print_percent_sign(va_list args, char buffer[],
	int flags, int width, int precision, int size);

/* Functions to print numbers */
int print_integer(va_list args, char buffer[],
	int flags, int width, int precision, int size);
int print_binary_number(va_list args, char buffer[],
	int flags, int width, int precision, int size);
int print_unsigned_number(va_list args, char buffer[],
	int flags, int width, int precision, int size);
int print_octal_number(va_list args, char buffer[],
	int flags, int width, int precision, int size);
int print_hexadecimal_number(va_list args, char buffer[],
	int flags, int width, int precision, int size);
int print_hexadecimal_upper_number(va_list args, char buffer[],
	int flags, int width, int precision, int size);

int print_hexadecimal_lower_or_upper(va_list args, char map_chars[], char buffer[],
	int flags, char flag_char, int width, int precision, int size);

/* Function to print non printable characters */
int print_unprintable_characters(va_list args, char buffer[],
	int flags, int width, int precision, int size);

/* Funcion to print memory address */
int print_memory_address(va_list args, char buffer[],
	int flags, int width, int precision, int size);

/* Funciotns to handle other specifiers */
int parse_flags(const char *format, int *index);
int calculate_width(const char *format, int *index, va_list args);
int calculate_precision(const char *format, int *index, va_list list);
int determine_size(const char *format, int *i);

/*Function to print string in reverse*/
int print_reversed_string(va_list args, char buffer[],
	int flags, int width, int precision, int size);

/*Function to print a string in rot 13*/
int print_rot13_encoded_string(va_list args, char buffer[],
	int flags, int width, int precision, int size);

/* width handler */
int handle_char_print(char c, char buffer[],
	int flags, int width, int precision, int size);
int handle_write_number(int is_negative, int ind, char buffer[],
	int flags, int width, int precision, int size);
int write_formatted_number(int ind, char buffer[],
	int flags, int width, int precision,
	int length, char padding, char extra_char);
int write_memory_address(char buffer[], int ind, int length,
	int width, int flags, char padding, char extra_char, int padding_start);

int handle_write_unsigned(int is_negative, int ind,
	char buffer[],
	int flags, int width, int precision, int size);

/****************** UTILS ******************/
int is_printable_character(char c);
int append_hexadecimal_code(char ascii_code, char buffer[], int index);
int is_decimal_digit(char c);

long int convert_to_size(long int num, int size);
unsigned long int convert_unsigned_to_size(unsigned long int num, int size);

#endif /* MAIN_H */
