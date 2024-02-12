/*
** EPITECH PROJECT, 2023
** my_swap
** File description:
** Swap the content of two integers,
** whose addresses are given as a parameter.
*/

void my_swap(int *a, int *b)
{
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;
}
