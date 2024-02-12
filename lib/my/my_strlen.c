/*
** EPITECH PROJECT, 2023
** my_strlen.c
** File description:
** Count and returns the number of characters
** found in the string passed as parameter.
*/

int my_strlen(char const *str)
{
    int carac;

    carac = 0;
    while (str[carac] != '\0') {
        carac = carac + 1;
    }
    return (carac);
}
