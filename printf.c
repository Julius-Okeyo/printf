#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include "main.h"
/**
 * _printf - mimics the behavior of printf
 * @format: string to be printed including string formatters
 * Return: The number of characters printed
 */

int _printf(const char *const format, ...)
{
	int a = 0, j = 0;
	int k, rem, num, div, sign = 0;
	char c;
	char *str;
	char *emp = "";
	va_list arg;

	if (format == NULL)
		return (-1);
	if (format == emp)
		return (0);

	va_start(arg, format);

	while (format[j] != '\n' && format[j] != '\0')
	{
		if (format[j] == '%')
		{
			if (format[j + 1] == 'c' || format[j + 1] == 'C')
			{
				c = va_arg(arg, int);
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
			}
			else
			{
				if (format[j + 1] == 's' || format[j + 1] == 'S')
				{
					str = va_arg(arg, char *);
					if (str == emp)
						continue;
					if (str == NULL)
						str = "(null)";
					while (*str)
					{
						_putchar(*str);
						a++;
						str++;
					}
				}
			       else
			       {
				       if (format[j + 1] == 'i' || format[j + 1] == 'I' || format[j + 1] == 'D' || format[j + 1] == 'd')
				       {
						k = 1;
						div = 10;
						rem = va_arg(arg, int);
						if (rem < 0)
						{
							sign = 1;
							rem = (-1 * rem);
						}
						num = rem;
						while (div >= 10)
						{
							k *= 10;
							div = num / k;
						}
						if (sign == 1)
							_putchar('-');
						while (rem > 10)
						{
							div = rem / k;
							rem = rem % k;
							_putchar(div + '0');
							a++;
							k /= 10;
						}
						_putchar(rem + '0');
						a++;
					}
				       else
				       {
					       _putchar(format[j]);
					       _putchar(format[j + 1]);
					       a += 2;
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
