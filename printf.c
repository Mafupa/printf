#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include "main.h"


/**
 * _printf - prints
 * @format: format of the string to print
 * Return: the number of characters printed
 */
int _printf(const char *format, ...)
{
	int i = 0, char_printed = 0;
	va_list args;

	va_start(args, format);
	while (format[i])
	{
		if (format[i] != '%' || (format[i] == '%' && format[i + 1] == '%'))
		{
			write(1, &format[i], 1);
			i++;
			char_printed++;
			continue;
		}
		handle_functions(format[i + 1], args, &char_printed, &i);
		i += 2;
		char_printed++;
	}
	va_end(args);
	return (char_printed);
}
