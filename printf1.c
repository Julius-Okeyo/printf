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
	int a = 0, j = 0, rem;
	char c;
	char *str;
	va_list arg;

	if (format == NULL)
		return (-1);
	va_start(arg, format);
	while (format[j] != '\0')
	{
		if (format[j] == '%')
		{
			switch(format[j + 1])
			{
				case 'c':
					c = va_arg(arg, int);
					a += print_char(c);
					break;
				case 's':
					str = va_arg(arg, char *);
					a += print_string(str);
					break;
				case 'S':
					str = va_arg(arg, char *);
					a += print_string(str);
					break;
				case 'i':
					rem = va_arg(arg, int);
					a += print_int(rem);
					break;
				case 'd':
					rem = va_arg(arg, int);
					a += print_int(rem);
					break;
				default:
			     		_putchar(format[j]);
			     	 	_putchar(format[j + 1]);
		    			a += 2;
					break;
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
	va_end(arg);
	return (a);
}
