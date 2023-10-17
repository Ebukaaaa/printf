#include "main.h"

/**
 * pnt_buffer - prints buffer
 * @buffer: buffer to print
 * @pointer: where to start printing
 */
void pnt_buffer(char *buffer, int *pointer)
{
	if (*pointer > 0)
	write(1, &buffer[0], *pointer);
	*pointer = 0;
}
/**
 * pnt_char - prints a character
 * @list: list to take info from
 * @buffer: buffer to print
 * @pointer: where to start printing
 * Return: 1 (Success), -1 (failure)
 */
int pnt_char(va_list list, char *buffer, int *pointer)
{
	int c = va_arg(list, int);
	char s = c;
	write(1, &s, 1);
	return (1);
}
/**
 * pnt_string - prints a string
 * @list: list to take info from
 * @buffer: buffer to print
 * @pointer: where to start printing
 * Return: (number of printed characters), -1 (failure)
 */
int pnt_string(va_list list, char *buffer, int *pointer)
{
	char *s = va_arg(list, char *);
	if (!s)
	s = "(null)";
	int count;
	for (count = 0; s[count]; count++)
	;
	return (write(1, s, count));
}
/**
 * pnt_percentage - prints a percentage
 * @list: list to take info from
 * @buffer: buffer to print
 * @pointer: where to start printing
 * Return: number of printed characters, -1 (failure)
 */
int pnt_percentage(va_list list, char *buffer, int *pointer)
{
	return (write(1, "%%", 1));
}
