/*
** EPITECH PROJECT, 2023
** my_put_nbr.c
** File description:
** my_put_nbr
*/
#include "include/my.h"
void limite(void)

{
    my_putchar('2');
    my_putchar('1');
    my_putchar('4');
    my_putchar('7');
    my_putchar('4');
    my_putchar('8');
    my_putchar('3');
    my_putchar('6');
    my_putchar('4');
    my_putchar('8');
}

int my_put_nbr(int nb)
{
    int count = 0;

    if (nb < 0) {
        count += my_putchar('-');
        nb *= (-1);
    }
    if (nb >= 0 && nb <= 9) {
        count += my_putchar(nb + 48);
    }
    if (nb == -2147483648) {
        limite();
    } else if (nb > 9) {
        count += my_put_nbr(nb / 10);
        count += my_putchar(nb % 10 + 48);
    }
    return count;
}
