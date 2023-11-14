#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
  * _printf - a function that produces output according to a format
  *
  * @format: to return the format
  * Return: Prints characters
  */

int _printf(const char *format, ...)
{
	va_list args;
	int length = 0;

	if (format == NULL)
		return (-1);

	va_start(args, format);

	length = _print_format(format, args);
	va_end(args);
	return (length);
}
