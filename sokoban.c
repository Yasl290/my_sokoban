/*
** EPITECH PROJECT, 2023
** B-PSU-100-LIL-1-1-sokoban-yanis.asselman
** File description:
** sokoban
*/

#include <ncurses.h>
#include "lib/my/include/my.h"
#include <stdlib.h>

int opening_check(int argc, char *argv[])
{
    if (argc < 2) {
        my_printf("No file target\n");
        exit(84);
    }
    return 0;
}

int help_display(void)
{
    FILE *file = fopen("./content/text.txt", "r");
    char ch;

    if (file == NULL) {
        my_printf("Erreur en ouvrant le fichier d'aide\n");
        return 84;
    }
    while (fread(&ch, 1, 1, file) == 1) {
        my_printf("%c", ch);
    }
    fclose(file);
    return 0;
}

int initialize(int argc, char *argv[])
{
    char *arg;

    for (int i = 1; i < argc; i++) {
        arg = argv[i];
        if (arg[0] == '-' && arg[1] == 'h' && arg[2] == '\0') {
            help_display();
            return 84;
        }
    }
}

int main(int argc, char *argv[])
{
    int result;

    if (initialize(argc, argv) == 84) {
        return 84;
    }
    opening_check(argc, argv);
    result = game_loop(argv);
    if (result == 1) {
        my_printf("Game Over: Toutes les boîtes sont bloquées.\n");
        return 1;
    } else {
        return 0;
    }
}
