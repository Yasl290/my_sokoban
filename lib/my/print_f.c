/*
** EPITECH PROJECT, 2023
** print_f.c
** File description:
** %f
*/

#include "include/my.h"

int printf_f(double nb, int precision)
{
    int count = 0;
    int whole = nb;

    if (whole == 0 && nb < 0)
        count += my_putchar('-');
    count += my_put_nbr(whole);
    count += my_putchar('.');
    nb = nb - whole;
    loop_printf_f(&nb, &precision);
    whole = nb;
    if (whole < 10 && nb == 0)
        my_putstr("00000");
    count += my_put_nbr(whole);
    return count;
}

int loop_printf_f(double *nb, int *precision)
{
    if (*nb < 0)
        *nb = -(*nb);
    for (int z = 1; z <= *precision; z++) {
        *nb *= 10;
    }
}
