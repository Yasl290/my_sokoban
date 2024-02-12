/*
** EPITECH PROJECT, 2023
** my_unsigned_X.c
** File description:
** unsigned upper X
*/

#include <stdlib.h>
#include "include/my.h"

int my_unsigned_upperx(unsigned int nb)
{
    int count;
    char *hexupper = NULL;
    int y = 0;

    hexupper = (char *)malloc(100 * sizeof(char));
    if (hexupper == NULL) {
        count += my_printf("84 error code \n");
        return count;
    }
    loop_upperx(nb, hexupper, &y, count);
    for (int r = y - 1; r >= 0; r--) {
        count += my_putchar(hexupper[r]);
    }
    free(hexupper);
    return count;
}

int loop_upperx(unsigned int nb, char *hexupper, int *y, int count)
{
    int temp;

    count = 0;
    while (nb != 0) {
        temp = 0;
        temp = nb % 16;
        if (temp < 10) {
            hexupper[*y] = temp + 48;
            count++;
            (*y)++;
        } else {
            hexupper[*y] = temp + 55;
            count++;
            (*y)++;
        }
        nb = nb / 16;
    }
    hexupper[*y] = '\0';
    return 0;
}
