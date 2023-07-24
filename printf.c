#include <stdio.h>
#include <stdarg.h>
#include "main.h"

int _printf(const char *format, ...)
{
    va_list args;
    int printed_chars = 0;

    va_start(args, format);

    while (*format)
    {
        if (*format == '%')
        {
            format++; /* Move past the '%' */

            /* Handle the conversion specifiers */
            switch (*format)
            {
                case 'c':
                {
                    char ch = (char)va_arg(args, int);
                    putchar(ch);
                    printed_chars++;
                    break;
                }
                case 's':
                {
                    char *str = va_arg(args, char *);
                    while (*str != '\0')
                    {
                        putchar(*str);
                        str++;
                        printed_chars++;
                    }
                    break;
                }
                case '%':
                    putchar('%');
                    printed_chars++;
                    break;
                default:
                    /* Ignore invalid conversion specifiers */
                    break;
            }
        }
        else
        {
            putchar(*format);
            printed_chars++;
        }
        format++; /* Move to the next character in the format string */
    }

    va_end(args);
    return printed_chars;
}

