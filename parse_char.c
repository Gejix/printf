#include "main.h"

/**
 * parse_char - returns the character
 * @buff_dest: character
 * @arg: list of arguments
 * @buff_count: index of buffer pointer
 * Return: typecasted argument
 */
int parse_char(char *buff_dest, va_list arg, int buff_count)
{
	char c = va_arg(arg, int);

	buff_dest[buff_count] = c;

	return (buff_count);
}
