#include "main.h"

/**
 * _printf - prints a formatted string
 * @format: the format string
 *
 * Return: the number of characters printed
 */
int _printf(const char *format, ...)
{
	int nchar = 0, i, pointer = 0;
	char buffer[BSIZE];
	int (*pnt_func)(va_list, char *, int *);
	va_list list;

	va_start(list, format);

	if (format == NULL)
		return (-1);

	for (i = 0; format[i]; i++)
	{
	if (format[i] != '%')
	{
		buffer[pointer++] = format[i];
		if (pointer == BSIZE)
		pnt_buffer(buffer, &pointer);
		nchar++;
	}
	else
	{
	pnt_buffer(buffer, &pointer);
	for (; format[i + 1] && format[i + 1] == ' '; i++)
	continue;

	pnt_func = get_print_func(format[i + 1]);

	if (pnt_func != NULL)
	{
		nchar += pnt_func(list, buffer, &pointer);
		i++;
		continue;
	}

	if (format[i + 1] == '\0')
	return (-1);

	write(1, "%%", 1);
	nchar++;
	}
	}

	pnt_buffer(buffer, &pointer);
	va_end(list);
	return (nchar);
}
