#include <stdio.h>
#include <stdarg.h>

int _printf(const char *format, ...) {
    va_list args;
    va_start(args, format);

    int printed_chars = 0;
    while (*format != '\0') {
        if (*format == '%') {
            format++; // Move past the '%'
            // Handle the conversion specifiers
            switch (*format) {
                case 'c': {
                    char ch = (char)va_arg(args, int);
                    putchar(ch);
                    printed_chars++;
                    break;
                }
                case 's': {
                    char *str = va_arg(args, char *);
                    while (*str != '\0') {
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
                    // Ignore invalid conversion specifiers
                    break;
            }
        } else {
            putchar(*format);
            printed_chars++;
        }
        format++; // Move to the next character in the format string
    }

    va_end(args);
    return printed_chars;
}

int main() {
    int chars_printed = _printf("This is a simple test.\n");
    printf("Characters printed: %d\n", chars_printed);

    chars_printed = _printf("Character: %c, String: %s, Percentage: %%\n", 'A', "Hello, World!");
    printf("Characters printed: %d\n", chars_printed);

    return 0;
}

