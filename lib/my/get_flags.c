/*
** EPITECH PROJECT, 2023
** get_flags.c
** File description:
** Get all the flags.
*/

#include "include/my.h"
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

static int lim_flag(char nb)
{
    if (nb != '-' && nb != '+' && nb != ' ' && nb != '#' && nb != '0') {
        return 0;
    }
    return 1;
}

static int str_to_nbr(char *str)
{
    int nbr = 0;
    int i = 0;

    for (i; str[i] != 0; i++) {
        nbr = (nbr * 10) + (str[i] - '0');
    }
    return nbr;
}

static int my_isnum(char c)
{
    if ('0' <= c && c <= '9') {
        return 1;
    }
    return 0;
}

void get_my_flag(const char *format, get_flag_t *flag, int *i)
{
    for (*i; lim_flag(format[*i]) == 1; (*i)++) {
        if (format[*i] == '-') {
            flag->my_flag.minus = 1;
        }
        if (format[*i] == '+') {
            flag->my_flag.plus = 1;
        }
        if (format[*i] == ' ') {
            flag->my_flag.space = 1;
        }
        if (format[*i] == '#') {
            flag->my_flag.diese = 1;
        }
        if (format[*i] == '0') {
            flag->my_flag.zero = 1;
        }
    }
}

void get_my_width(const char *format, get_flag_t *flag, int *i)
{
    char *str;
    int j = 0;
    int len = my_strlen(format);

    str = malloc(100 * sizeof(char) * len);
    for (*i; my_isnum(format[(*i)]) == 1; (*i)++) {
        str[j] = format[*i];
        j++;
    }
    str[j] = '\0';
    flag->my_width = str_to_nbr(str);
    free(str);
}

static void precision(const char *format, get_flag_t *flag, int *i)
{
    char *str;
    int j = 0;
    int len = my_strlen(format);

    str = malloc(100 * sizeof(char) * len);
    for (*i; my_isnum(format[*i]) == 1; (*i)++) {
        str[j] = format[*i];
        j++;
    }
    str[j] = '\0';
    flag->my_precision = str_to_nbr(str);
    free(str);
}

void get_my_precision(const char *format, get_flag_t *flag, int *i)
{
    for (int k = 0; format[k] != 0; k++) {
        if (format[*i] == '.') {
            (*i)++;
            precision(format, flag, i);
            break;
        }
        flag->my_precision = 0;
    }
}

void get_my_length(const char *format, get_flag_t *flag, int *i)
{
    char length[6] = "hljztL";

    for (int j = 0; length[j] != 0; j++) {
        if (format[*i] == length[j]) {
            flag->my_length = format[*i];
            (*i)++;
            break;
        }
    }
}

static void get_my_specifier(const char *format, get_flag_t *flag, int *i)
{
    char specifier[12] = "disc%puoxXfF";

    for (int j = 0; specifier[j] != 0; j++) {
        if (format[*i] == specifier[j]) {
            flag->my_specifier = format[*i];
        }
    }
}

get_flag_t get_all_flags(const char *format, int *i)
{
    get_flag_t flag;

    (*i)++;
    get_my_flag(format, &flag, i);
    get_my_width(format, &flag, i);
    get_my_precision(format, &flag, i);
    get_my_length(format, &flag, i);
    get_my_specifier(format, &flag, i);
    return flag;
}
