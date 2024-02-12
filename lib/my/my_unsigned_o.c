/*
** EPITECH PROJECT, 2023
** my_unsigned_o.c
** File description:
** unsigned octal
*/
#include "include/my.h"

int my_unsigned_o(unsigned int nb)
{
    int count = 0;

    if (nb >= 0 && nb <= 7) {
        count += my_putchar(nb + 48);
    } else if (nb > 7) {
        count += my_unsigned_o(nb / 8);
        count += my_putchar(nb % 8 + 48);
    }
    return count;
}
