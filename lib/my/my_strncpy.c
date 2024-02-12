/*
** EPITECH PROJECT, 2023
** my_strncpy.c
** File description:
** Copy n characters from a string into another.
*/

char *my_strncpy(char *dest, char const *src, int n)
{
    int y;

    for (y = 0; y < n && src[y] != '\0'; y++){
        dest[y] = src[y];
    }
    for (; y < n; y++) {
        dest[y] = '\0';
    }
    return (dest);
}
