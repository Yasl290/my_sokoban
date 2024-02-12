/*
** EPITECH PROJECT, 2023
** my_unsigned_nbr?c
** File description:
** unsigned put nbr version
*/
#include "include/my.h"
void limit(void)

{
    my_putchar('4');
    my_putchar('2');
    my_putchar('9');
    my_putchar('4');
    my_putchar('9');
    my_putchar('6');
    my_putchar('7');
    my_putchar('2');
    my_putchar('9');
    my_putchar('5');
}

int my_unsigned_nbr(unsigned int nb)
{
    int count = 0;

    if (nb >= 0 && nb <= 9) {
        count += my_putchar(nb + 48);
    } else if (nb > 9) {
        count += my_put_nbr(nb / 10);
        count += my_putchar(nb % 10 + 48);
    }
    return count;
}
