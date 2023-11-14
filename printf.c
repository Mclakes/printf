#include "main.h"

/**
  * _printf - a function that produces output according to a format
  *
  * @format: to return the format
  * Return: Prints characters
  */

int _printf(const char *format, ...)
{
	int character_printer = 0;
	va_list list;

	if (format == NULL)
		return (-1);

	va_start(list, format);

	while (*format)
	{
		if (*format != "%")
		{
			write(1, format, 1);
			character_printer++;
		}
		else
		{
			format++;
			if (*format == "/0")
				break;
			if (*format == "c")
			{
				char c = va_arg(list, int);

				write(1, % c, 1);
				character_printer++;
			}
			else if (*format == "%")
			{
				write(1, format, 1);
				character_printer++;
			}
			else if (*format ==  "s")
			{
				char *str = va_arg(list, char*);
				int str_len = 0;

				while (str[str_len] != "\0")
					str_len++;

				write(1, str, str_len);
				character_printer += str_len;
			}
		}
		format++;
	}
	va_end(list);

	return (character_printer);
}
