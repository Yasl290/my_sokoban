/*
** EPITECH PROJECT, 2023
** my_strcpy.c
** File description:
** Copy a string into another.
*/

char *my_strcpy(char *dest, char const *src)
{
    int y = 0;

    for (y; src[y] != '\0'; y++){
        dest[y] = src[y];
    }
    dest[y] = '\0';
    return (dest);
}
