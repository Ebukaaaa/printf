#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

#define BSIZE 1024
#define VOIDED(x) (void)(x)
#define ABS(x)((x < 0) ? -(x) : x)

/**
 * struct print_functions - Struct print_functions
 *
 * @spc: The specificer
 * @f: The function associated
 */
typedef struct print_functions
{
        char spc;
        int (*f)(va_list, char *, int *);
} pnt;

int _printf(const char *format, ...);
int (*get_print_func(char spc))(va_list, char *, int *);
/* Print functions */
int pnt_char(va_list list, char *, int *);
int pnt_string(va_list list, char *, int *);
int pnt_percentage(va_list list, char *buffer, int *pointer);
int pnt_number(va_list list, char *buffer, int *pointer);
/*Buffer printer*/
void pnt_buffer(char *, int *);
int _putchar(char c);

#endif
