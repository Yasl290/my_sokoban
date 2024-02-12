/*
** EPITECH PROJECT, 2023
** my_putstr.c
** File description:
** my_putstr
*/
#include <unistd.h>

int my_putstr(char *s)
{
    int len = 0;

    while (s[len] != '\0') {
        len++;
    }
    write(1, s, len);
    return len;
}
