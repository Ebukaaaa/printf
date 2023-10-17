#include "main.h"

/**
 * get_print_func - gets function based on specifier
 * @spc: specifier passed
 *
 * Return: pointer to the function
 */

int (*get_print_func(char spc))(va_list, char *, int *)
{
	pnt pnt_f[] = {
		{'c', pnt_char},
		{'s', pnt_string},
		{'%', pnt_percentage},
		{'\0', NULL}
	};
	int i = 0;

	while (pnt_f[i].spc != '\0')
	{
		if (pnt_f[i].spc == spc)
			return (pnt_f[i].f);
		++;
	}

	return (NULL);
}
