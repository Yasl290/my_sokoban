/*
** EPITECH PROJECT, 2023
** my_compute_power_rec.c
** File description:
** Return the first argument raised to the power p, where p is the second
** argument.
*/

int my_compute_power_rec(int nb, int power)
{
    if (power == 0) {
        return 1;
    }
    if (power < 0) {
        return 0;
    }
    return nb * my_compute_power_rec(nb, power - 1);
}
