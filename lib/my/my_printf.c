/*
** EPITECH PROJECT, 2023
** my_printf.c
** File description:
** my_printf
*/

#include "include/my.h"
#include <stdarg.h>
#include <unistd.h>

get_flag_t use_fa(const char *format, va_list list, int *i, int *count)
{
    get_flag_t flag;
    char specifier[12] = "disc%puoxXfF";
    int (*functionArray[12])(const char *, va_list, int, get_flag_t) = {
        print_d, print_i, print_s, print_c,
        print_percent, print_p, print_u,
        print_o, print_lowerx, print_upperx, print_f, print_upperf};

    flag = get_all_flags(format, i);
    for (int j = 0; specifier[j] != 0; j++) {
        if (flag.my_specifier == specifier[j]) {
            *count += functionArray[j] (format, list, i, flag);
        }
    }
    return flag;
}

int print_n(const char *format, va_list list, int *i, int counter)
{
    if (format[*i] == '%') {
        if (format[*i + 1] == 'n') {
            (*va_arg(list, int *)) = counter;
            (*i)++;
        }
    }
}

int my_printf(const char *format, ...)
{
    va_list list;
    int i = 0;
    int count = 0;
    get_flag_t flag;
    int *p = &i;

    va_start(list, format);
    while (format[i] != 0) {
        if (format[i] == '%') {
            flag = use_fa(format, list, p, &count);
        } else {
            my_putchar(format[i]);
            count++;
        }
        i++;
        print_n(format, list, &i, count);
    }
    va_end(list);
    return count;
}
