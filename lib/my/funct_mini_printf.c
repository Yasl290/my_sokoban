/*
** EPITECH PROJECT, 2023
** funct_mini_printf.c
** File description:
** function from mini_printf
*/

#include "include/my.h"
#include <stdarg.h>
#include <unistd.h>

int print_d(const char *specifier, va_list list, int i, get_flag_t flag)
{
    int count = 0;
    int arg_int = va_arg(list, int);

    count += front_padding_int(flag, arg_int);
    count += print_space_plus(flag, arg_int);
    count += my_put_nbr(arg_int);
    count += back_padding_int(flag, arg_int);
    return count;
}

int print_i(const char *specifier, va_list list, int i, get_flag_t flag)
{
    int count = 0;
    int arg_int = va_arg(list, int);

    count += front_padding_int(flag, arg_int);
    count += print_space_plus(flag, arg_int);
    count += my_put_nbr(arg_int);
    count += back_padding_int(flag, arg_int);
    return count;
}

int print_s(const char *specifier, va_list list, int i, get_flag_t flag)
{
    int count = 0;
    char *arg_str = va_arg(list, char *);

    count += front_padding_str(flag, arg_str);
    count += my_putstr(arg_str);
    count += back_padding_str(flag, arg_str);
    return count;
}

int print_c(const char *specifier, va_list list, int i, get_flag_t flag)
{
    int count = 0;

    count += front_padding_char(flag);
    count += my_putchar(va_arg(list, int));
    count += back_padding_char(flag);
    return count;
}

int print_percent(const char *specifier, va_list list, int i, get_flag_t flag)
{
    int count = 0;

    count += my_putchar('%');
    return count;
}
