#include <stdarg.h>
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
	int a = 0, i = 0, j = 0;
	int k, rem, num, div, sign = 0;
	char c;
	/*char *emp = "";*/
	va_list arg;

	if (format == NULL && i == 0)
		return (-1);
	if (format == NULL && i == 1)
		_printf("(null)");
	/*if (format == emp && i == 0)
		return (0);*/

	va_start(arg, format);

	while (format[j])
	{
		if (format[j] == '%')
		{
			switch (format[j + 1]) {
				case 'c':
					c = va_arg(arg, int);
					if (c == 0)
					{
						_putchar(' ');
						a++;
					}
					else
					{
						_putchar(c);
						a++;
					}
					break;
				case 's':
					i = 1;
					_printf(va_arg(arg, char *));
					break;
				case 'i':
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
					break;
				case 'd':
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
	if (format[j] != '\n')
	{
		_putchar('\n');
	}
	va_end(arg);
	return (a);
}
