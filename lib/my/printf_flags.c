/*
** EPITECH PROJECT, 2023
** printf_flags.c
** File description:
** some specifiers
*/
#include "include/my.h"
#include <stdarg.h>
#include <unistd.h>

int print_p(const char *specifier, va_list list, int i, get_flag_t flag)
{
    int count = 0;
    void *valeur = va_arg(list, void *);

    if (valeur == NULL) {
        my_putstr("(nil)");
        return 5;
    }
    count += print_hex_address(valeur);
    return count;
}

int print_hex_address(void *ptr)
{
    unsigned long long address = (unsigned long long)ptr;
    char hex_string[16];
    int counter = 0;
    int nibble;

    for (int i = 0; i < 16; i++) {
        nibble = (address >> (60 - 4 * i)) & 0xF;
        if (nibble < 10) {
            hex_string[i] = '0' + nibble;
        } else {
            hex_string[i] = 'a' + (nibble - 10);
        }
    }
    my_putstr("0x");
    counter += 2;
    for (int i = 4; i < 16; i++) {
        my_putchar(hex_string[i]);
        counter++;
    }
    return counter;
}

int print_f(const char *specifier, va_list list, int i, get_flag_t flag)
{
    int count = 0;
    double arg_double = va_arg(list, double);
    int precision = 6;

    if (flag.my_precision != 0) {
        precision = flag.my_precision;
    }
    count += printf_f(arg_double, precision);
    return count;
}

int print_upperf(const char *specifier, va_list list, int i, get_flag_t flag)
{
    int count = 0;
    double arg_double = va_arg(list, double);
    int precision = 6;

    if (flag.my_precision != 0) {
        precision = flag.my_precision;
    }
    count += printf_upperf(arg_double, precision);
    return count;
}
