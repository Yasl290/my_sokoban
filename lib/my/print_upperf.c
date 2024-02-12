/*
** EPITECH PROJECT, 2023
** print_upperf.c
** File description:
** print upper f function
*/
#include "include/my.h"
int printf_upperf(double nb, int precision)
{
    int count = 0;
    int wholer = nb;

    if (wholer == 0 && nb < 0)
        count += my_putchar('-');
    count += my_put_nbr(wholer);
    count += my_putchar('.');
    nb = nb - wholer;
    loop_printf_upperf(&nb, &precision);
    wholer = nb;
    if (wholer < 10 && nb == 0)
        my_putstr("00000");
    count += my_put_nbr(wholer);
    return count;
}

int loop_printf_upperf(double *nb, int *precision)
{
    if (*nb < 0)
        *nb = -(*nb);
    for (int z = 1; z <= *precision; z++) {
        *nb *= 10;
    }
}
