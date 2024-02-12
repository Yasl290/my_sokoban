/*
** EPITECH PROJECT, 2023
** padding.c
** File description:
** Padding of the function
*/

#include "include/my.h"
#include <stdarg.h>
#include <unistd.h>

static int my_nbrlen(int nbr)
{
    int i = 0;

    if (nbr < 0) {
        i = 1;
        nbr *= -1;
    }
    if (nbr == 0) {
        i = 1;
    }
    for (i; nbr != 0; i++) {
        nbr = nbr / 10;
    }
    return i;
}

static void print(char chr, int nb)
{
    int i = 1;

    while (i <= nb) {
        my_putchar(chr);
        i = i + 1;
    }
}

int plus_flag(get_flag_t flag, int arg_int)
{
    if (flag.my_flag.plus == 1 && arg_int > 0) {
            return 1;
    }
    return 0;
}

int space_flag(get_flag_t flag, int arg_int)
{
    if (flag.my_flag.space == 1 && arg_int > 0) {
        return 1;
    }
    return 0;
}

int print_space_plus(get_flag_t flag, int arg_int)
{
    if (plus_flag(flag, arg_int) == 1) {
            my_putchar('+');
            return 1;
        } else if (space_flag(flag, arg_int) == 1) {
            my_putchar(' ');
            return 1;
        }
    return 0;
}

int front_padding_int(get_flag_t flag, int arg_int)
{
    int difference = flag.my_width - my_nbrlen(arg_int);
    char print_padding = ' ';

    if (flag.my_specifier == 'd' || flag.my_specifier == 'i') {
        difference -= plus_flag(flag, arg_int);
        difference -= space_flag(flag, arg_int);
    }
    if (flag.my_flag.minus == 1) {
        return 0;
    }
    if (flag.my_flag.zero == 1) {
        print_padding = '0';
    }
    if (difference > 0) {
        print(print_padding, difference);
        return difference;
    }
    return 0;
}

int back_padding_int(get_flag_t flag, int arg_int)
{
    int difference = flag.my_width - my_nbrlen(arg_int);
    char print_padding = ' ';

    difference -= plus_flag(flag, arg_int);
    difference -= space_flag(flag, arg_int);
    if (flag.my_flag.minus == 1) {
        if (difference > 0) {
            print(print_padding, difference);
            return difference;
        }
        return 0;
    }
    return 0;
}
