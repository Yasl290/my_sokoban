/*
** EPITECH PROJECT, 2023
** my_revstr.c
** File description:
** Reverse a string.
*/

char *my_revstr(char *str)
{
    int len = my_strlen(str);
    char temp;
    int i = 0;

    while (i < len / 2) {
        temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
        i++;
    }
    return str;
}
