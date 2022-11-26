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
	char *emp = "";
	char *str;
	va_list arg;

	if (format == NULL)
	{
		_printf("error: too few arguments to function '_printf'\n");
		exit (1);
	}
	if (format == emp)
	{
		_putchar('\n');
		return (1);
	}
	va_start(arg, format);
	while (format[j])
	{
		if (format[j] == '%')
		{
			j++;
			switch (format[j]) {
				case 'c':
					c = va_arg(arg, int);
					if (c == 0)
						_putchar('\n');
					else
					{
						_putchar(c);
						a++;
					}
					break;
				case 's':
					str = va_arg(arg, char *);
					if (str != NULL)
					{
						while (str[i])
						{
							if (str[i] >= 32 && str[i] <= 126)
							{
								_putchar(str[i]);
								a++;
							}
							i++;
						}
					}
					else
					{
						_printf("(null)\n");
					}
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
		}
		else
			_putchar(format[j]);
		a++;
		j++;
	}
	va_end(arg);
	return (a);
}
