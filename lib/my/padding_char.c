/*
** EPITECH PROJECT, 2023
** padding_char.c
** File description:
** Padding of the char functions.
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

int front_padding_str(get_flag_t flag, char *arg_str)
{
    int difference = flag.my_width - my_strlen(arg_str);
    char print_padding = ' ';

    if (flag.my_flag.minus == 1) {
        return 0;
    }
    if (difference > 0) {
        print(print_padding, difference);
        return difference;
    }
    return 0;
}

int back_padding_str(get_flag_t flag, char *arg_str)
{
    int difference = flag.my_width - my_strlen(arg_str);
    char print_padding = ' ';

    if (flag.my_flag.minus == 1) {
        if (difference > 0) {
            print(print_padding, difference);
            return difference;
        }
        return 0;
    }
    return 0;
}

int front_padding_char(get_flag_t flag)
{
    int difference = flag.my_width - 1;
    char print_padding = ' ';

    if (flag.my_flag.minus == 1) {
        return 0;
    }
    if (difference > 0) {
        print(print_padding, difference);
        return difference;
    }
    return 0;
}

int back_padding_char(get_flag_t flag)
{
    int difference = flag.my_width - 1;
    char print_padding = ' ';

    if (flag.my_flag.minus == 1) {
        if (difference > 0) {
            print(print_padding, difference);
            return difference;
        }
        return 0;
    }
    return 0;
}
