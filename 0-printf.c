#include <stdarg.h>
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
	int k, rem, num, div;
	char c;
	char *str;
	va_list arg;

	va_start(arg, format);
	while (format[j])
	{
		if (format[j] == '%')
		{
			j++;
			switch (format[j]) {
				case 'c':
					c = va_arg(arg, int);
					if (c >= 32 && c <= 126)
					{
						_putchar(c);
						a++;
					}
					break;
				case 's':
					str = va_arg(arg, char *);
					if (str != NULL)
					{
						while (*str)
						{
							if (*str >= 32 && *str <= 126)
							{
								_putchar(*str);
								a++;
							}
							str++;
						}
					}
					_putchar('\0');
					break;
			}
		}
		else
			_putchar(format[j]);
		a++;
		j++;
	}
	va_end(arg);
	return (a);
}
