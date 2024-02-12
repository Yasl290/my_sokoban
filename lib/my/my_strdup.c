/*
** EPITECH PROJECT, 2023
** B-PSU-100-LIL-1-1-sokoban-yanis.asselman
** File description:
** my_strdup
*/

#include <stdlib.h>

char *my_strdup(const char *src)
{
    char *dup;
    int length = 0;

    while (src[length] != '\0') {
        length++;
    }
    dup = malloc((length + 1) * sizeof(char));
    if (dup == NULL) {
        return NULL;
    }
    for (int i = 0; i <= length; i++) {
        dup[i] = src[i];
    }
    return dup;
}
