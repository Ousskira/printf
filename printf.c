#include "main.h"

int _printf(const char *format, ...) {
    va_list args;
    int count = 0;

    va_start(args, format);

    while (*format != '\0') {
        if (*format == '%') {
            format++;

            switch (*format) {
                case 'c': {
                    char c = (char) va_arg(args, int);
                    putchar(c);
                    count++;
                    break;
                }
                case 's': {
                    const char *str = va_arg(args, const char *);
                    while (*str != '\0') {
                        putchar(*str);
                        str++;
                        count++;
                    }
                    break;
                }
                case 'd':
                case 'i': {
                    int num = va_arg(args, int);
                    printf("%d", num);
                    count++;
                    break;
                }
                case 'u': {
                    unsigned int num = va_arg(args, unsigned int);
                    printf("%u", num);
                    count++;
                    break;
                }
                case 'x': {
                    unsigned int num = va_arg(args, unsigned int);
                    printf("%x", num);
                    count++;
                    break;
                }
		case 'X': {
		    unsigned int num = va_arg(args, unsigned int);
                    printf("%X", num);
                    count++;
                    break;
  		}
		case 'o': {
		    unsigned int num = va_arg(args, unsigned int);
                    printf("%o", num);
                    count++;
                    break;
  		}    
                case 'p': {
                    void *ptr = va_arg(args, void *);
                    printf("%p", ptr);
                    count++;
                    break;
                }
                case '%':
                    putchar('%');
                    count++;
                    break;
                default:
                    putchar('%');
                    putchar(*format);
                    count += 2;
                    break;
            }
        } else {
            putchar(*format);
            count++;
        }
        format++;
    }

    va_end(args);

    return count;
}
