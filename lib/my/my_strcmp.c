/*
** EPITECH PROJECT, 2023
** my_strcmp
** File description:
** Compare two strings.
*/

int my_strcmp(char const *uno, char const *dos)
{
    for (int i = 0;; i++) {
        if (uno[i] != dos[i]) {
            return (uno[i] - dos[i]);
        }
        if (uno[i] == '\0') {
            return 0;
        }
    }
}
