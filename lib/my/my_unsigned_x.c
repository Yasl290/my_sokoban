/*
** EPITECH PROJECT, 2023
** my_unsigned_x.c
** File description:
** unsigned hexadecimal
*/
#include <stdlib.h>
#include "include/my.h"
int my_unsigned_x(unsigned int nb)
{
    int count;
    char *hexlower = NULL;
    int y = 0;
    int temp;

    hexlower = (char *)malloc(100 * sizeof(char));
    if (hexlower == NULL) {
        count += my_printf("84 error code \n");
        return count;
    }
    loop_x(nb, hexlower, &y, count);
    for (int r = y - 1; r >= 0; r--) {
        count += my_putchar(hexlower[r]);
    }
    free(hexlower);
    return count;
}

int loop_x(unsigned int nb, char *hexlower, int *y, int count)
{
    int temp;

    count = 0;
    while (nb != 0) {
        temp = 0;
        temp = nb % 16;
        if (temp < 10) {
            hexlower[*y] = temp + 48;
            count ++;
            (*y)++;
        } else {
            hexlower[*y] = temp + 87;
            count++;
            (*y)++;
        }
        nb = nb / 16;
    }
    hexlower[*y] = '\0';
    return 0;
}
