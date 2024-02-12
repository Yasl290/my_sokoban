/*
** EPITECH PROJECT, 2023
** unsigned_flags.c
** File description:
** unsigned flags functions
*/
#include "include/my.h"
int print_u(const char *specifier, va_list list, int i, get_flag_t flag)
{
    int count = 0;
    int arg_int = va_arg(list, int);

    count += front_padding_int(flag, arg_int);
    count += my_unsigned_nbr(arg_int);
    count += back_padding_int(flag, arg_int);
    return count;
}

int print_o(const char *specifier, va_list list, int i, get_flag_t flag)
{
    int count = 0;
    int arg_int = va_arg(list, int);

    count += front_padding_int(flag, arg_int);
    count += my_unsigned_o(arg_int);
    count += back_padding_int(flag, arg_int);
    return count;
}

int print_lowerx(const char *specifier, va_list list, int i, get_flag_t flag)
{
    int count = 0;
    int arg_int = va_arg(list, int);

    count += front_padding_int(flag, arg_int);
    count += my_unsigned_x(arg_int);
    count += back_padding_int(flag, arg_int);
    return count;
}

int print_upperx(const char *specifier, va_list list, int i, get_flag_t flag)
{
    int count = 0;
    int arg_int = va_arg(list, int);

    count += front_padding_int(flag, arg_int);
    count += my_unsigned_upperx(arg_int);
    count += back_padding_int(flag, arg_int);
    return count;
}
