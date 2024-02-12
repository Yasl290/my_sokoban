/*
** EPITECH PROJECT, 2023
** B-CPE-110-LIL-1-1-organized-yanis.asselman
** File description:
** my_atoi
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int my_atoi(const char *str)
{
    int res = 0;
    int sign = 1;
    int i = 0;

    if (str[i] == '-') {
        sign = -1;
        i++;
    } else if (str[i] == '+') {
        i++;
    }
    while (str[i] != '\0') {
        if (str[i] < '0' || str[i] > '9') {
            break;
        }
        res = res * 10 + (str[i] - '0');
        i++;
    }
    return sign *res;
}
