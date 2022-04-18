#include "main.h"

/**
 * _printf - formatted output conversion and print data.
 * @format: input string.
 *
 * Return: number of chars printed.
 */

int _printf(const char *format, ...)
{
	va_list arg;
	unsigned int i, buff_count;
	char* buffer;

	if (!format)
		return (-1);

	buffer = malloc(sizeof(char) * 1500);
	if (!buffer)
	{
		return (-1);
		free(buffer);
	}

	va_start(arg, format);
	i = 0, buff_count = 0;
	while (format && format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			switch (format[i])
			{
				case '%':
						buffer[buff_count] = '%', buff_count++;
						break;
				case 'c':
						buff_count = parse_char(buffer, arg, buff_count); buff_count++;
						break;
				case 's':
						buff_count = parse_string(buffer, arg, buff_count); buff_count++;
						break;
				default:
						i--;
						buffer[buff_count] = '%';
						buffer[buff_count] = format[i], buff_count++;
			}
		}
		else
		{
			buffer[buff_count] = format[i];
			buff_count++;
		}
		i++;
	}
	buffer[buff_count] = '\0';
	print_buff(buffer, buff_count++);
	va_end(arg);
	return(buff_count);
}
