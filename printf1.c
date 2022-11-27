#include <stdarg.h>
#include <stdlib.h>
#include <stddef.h>
#include "main.h"

/**
 * print_char - prints a character
 * @c: character to be printed
 * Return: The number of characters printed
 */

int print_char(char c)
{
	int a = 0;

	if (c != 0)
	{
		_putchar(c);
		a++;
	}
	if (c == 0)
	{
		_putchar(' ');
		a++;
	}
	return (a);
}

/**
 * print_string - prints a string
 * @str: string to be printed
 * Return: number of characters printed
 */

int print_string(char *str)
{
	int a = 0;
	char *emp = "";

	if (str == emp)
		return (0);
	if (str == NULL)
		str = "(null)";
	while (*str)
	{
		_putchar(*str);
		a++;
		str++;
	}
	return (a);
}

/**
 * print_int - prints a integer
 * rem: integer to be printed
 * Return: The number of characters printed
 */

int print_int(int rem)
{
	int num, k = 1, div = 10, sign = 0, a = 0;
	
	if (rem < 0)
	{
		sign = 1;
		rem *= -1;
	}
	num = rem;
	while (div >= 10)
	{
		k *= 10;
		div = num / k;
	}
	if (sign == 1)
	{
		_putchar('-');
		a++;
	}
	while (rem > 10)
	{
		div = rem / k;
		rem %= k;
		_putchar(div + '0');
		a++;
		k /= 10;
	}
	_putchar(rem + '0');
	a++;
	return (a);
}

/**
 * _printf - mimics the behavior of printf
 * @format: string to be printed including string formatters
 * Return: The number of characters printed
 */

int _printf(const char *const format, ...)
{
	int a = 0, j = 0, i, z, rem;
	char c;
	char *str;
	char *emp = "";
	va_list arg;

	if (format == NULL)
		return (-1);
	if (format == emp)
	{
		_putchar('\0');
		_putchar('\n');
		return (1);
	}

	va_start(arg, format);

	while (format[j] != '\n' && format[j] != '\0')
	{
		if (format[j] == '%')
		{
			if (format[j + 1] == 'c' || format[j + 1] == 'C')
			{
				c = va_arg(arg, int);
				a += print_char(c);
			}
			else
			{
				if (format[j + 1] == 's')
				{
					str = va_arg(arg, char *);
					a += print_string(str);
				}
			       else
			       {
				       if (format[j + 1] == 'i' || format[j + 1] == 'd')
				       {
						rem = va_arg(arg, int);
						a += print_int(rem);
				       }
				       else
				       {
					       if (format[j + 1] >= 48 && format[j + 1] <= 57)
					       {
						       z = (int)(format[j + 1] - 48);
						       for (i = 0; i < z; i++)
						       {
							       _putchar(' ');
							       a++;
						       }
						       j++;
						       if (format[j + 1] == 'i' || format[j + 1] == 'd')
						       {
							       rem = va_arg(arg, int);
							       a += print_int(rem);
						       }
					       }
					       else
					       {
						       _putchar(format[j]);
						       _putchar(format[j + 1]);
						       a += 2;
					       }
				       }
			       }
			}
			j++;
		}
		else
		{
			_putchar(format[j]);
			a++;
		}
		j++;
	}
	_putchar('\n');
	a++;
	va_end(arg);
	return (a);
}
