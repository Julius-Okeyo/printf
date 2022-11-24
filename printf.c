#include <stdarg.h>
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
					while (*str)
					{
						if (*str >= 32 && *str <= 126)
						{
							_putchar(*str);
							a++;
						}
						str++;
					}
					_putchar('\0');
					break;
				case 'i':
					k = 1;
					div = 10;
					rem = va_arg(arg, int);
					num = rem;
					while (div >= 10)
					{
						k *= 10;
						div = num / k;
					}
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
					num = rem;
					while (div >= 10)
					{
						k *= 10;
						div = num / k;
					}
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
		}
		else
			_putchar(format[j]);
		a++;
		j++;
	}
	va_end(arg);
	return (a);
}
