#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include "main.h"

/**
 * print_string - prints a string
 * @s: the string
 * Return: the size of the string
 */
int print_string(char *s)
{
	int i = 0;

	while (s[i])
		i++;
	write(1, s, i);
	return (i);
}

/**
 * print_number - prints an integer
 * @n: the integer
 * @cp: pointer to character count
 */
void print_number(int n, int *cp)
{
	int m;
	char temp_c;

	if (n < 0)
	{
		m = -n;
		write(1, "-", 1);
	}
	else
	{
		m = n;
	}
	if (m / 10)
		print_number((m / 10), cp);
	temp_c = (m % 10) + '0';
	write(1, &temp_c, 1);
	(*cp)++;
}

/**
 * print_unsigned - prints positive integer
 * @n: the unsigned integer
 * @cp: pointer to character count
 */
void print_unsigned(unsigned int n, int *cp)
{
	char temp_c;

	if (n / 10)
		print_unsigned((unsigned int)(n / 10), cp);
	temp_c = (n % 10) + '0';
	write(1, &temp_c, 1);
	(*cp)++;
}

/**
 * dectobase - prints a decimal number's binary equivalent
 * @n: the decimal number
 * @d: the new base
 * @maj: 1 for maj letters 0 for min
 * @cp: pointer to character printed counter
 */
void dectobase(unsigned int n, unsigned int d, int maj, int *cp)
{
	char binary[32];
	int i = 0, j, remainder;

	if (n == 0)
	{
		write(1, "0", 1);
		(*cp)++;
		return;
	}
	while (n > 0)
	{
		remainder = n % d;
		if (remainder < 10)
			binary[i] = remainder + '0';
		else if (maj == 0)
			binary[i] = remainder - 10 + 'a';
		else
			binary[i] = remainder - 10 + 'A';
		n = n / d;
		i++;
	}
	for (j = i - 1; j >= 0; j--)
	{
		write(1, &binary[j], 1);
		(*cp)++;
	}
}


/**
 * handle_functions - handle the functions
 * @c: character for function
 * @args: arguments
 * @char_printed: char printed counter
 */
void handle_functions(char c, va_list args, int *char_printed)
{
	char temp_c;

	switch (c)
	{
		case 'c':
			temp_c = va_arg(args, int);
			write(1, &temp_c, 1);
			(*char_printed)++;
			break;
		case 's':
			char_printed += print_string(va_arg(args, char *));
			break;
		case '%':
			write(1, "%", 1);
			(*char_printed)++;
			break;
		case 'd':
		case 'i':
			print_number(va_arg(args, int), char_printed);
			break;
		case 'u':
			print_unsigned(va_arg(args, unsigned int), char_printed);
			break;
		case 'b':
			dectobase(va_arg(args, int), 2, 0, char_printed);
			break;
		case 'o':
			dectobase(va_arg(args, int), 8, 0, char_printed);
			break;
		case 'x':
			dectobase(va_arg(args, int), 16, 0, char_printed);
			break;
		case 'X':
			dectobase(va_arg(args, int), 16, 1, char_printed);
			break;
		default:
			write(1, "%", 1);
			write(1, &c, 1);
			(*char_printed) += 2;
	}
}
