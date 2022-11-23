#include <stdarg.h>
#include "main.h"
/**
 * _printf - mimics the behavior of printf
 * @format: string to be printed including string formatters
 * Return: The number of characters printed
 */
int _printf(const char *const format, ...)
{
	int a = 0, b = 0, i, j = 0;
	int d, k, rem, num, div;
	char c;
	char *s;
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
					_putchar(c);
					a++;
					break;
				case 's':
					str = va_arg(arg, char *);
					while (*str)
					{
						_putchar(*str);
						a++;
						str++;
					}
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
						_putcar(div + '0');
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
						div = mum / k;
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
				j++;
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
