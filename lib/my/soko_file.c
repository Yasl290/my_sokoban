/*
** EPITECH PROJECT, 2023
** B-PSU-100-LIL-1-1-sokoban-yanis.asselman
** File description:
** soko_file
*/

#include "include/my.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <ncurses.h>

void buf_er(char **buffer, int *f, const char *fpth, struct stat *file_stat)
{
    *buffer = malloc(file_stat->st_size + 1);
    if (*buffer == NULL) {
        my_printf("Erreur d'allocation mémoire\n");
        exit(84);
    }
    *f = open(fpth, O_RDONLY);
    if (*f == -1) {
        my_printf("Malloc error\n");
        free(*buffer);
        exit(84);
    }
    if (read(*f, *buffer, file_stat->st_size) == -1) {
        my_printf("Erreur lors de la lecture du fichier\n");
        free(*buffer);
        exit(84);
    }
    (*buffer)[file_stat->st_size] = '\0';
}

char int_to_char(int val)
{
    switch (val) {
        case 0:
            return 'X';
        case 1:
            return 'O';
        case 2:
            return 'P';
        case 3:
            return '#';
        case 4:
            return '\n';
        case 5:
            return ' ';
        case -1:
            my_printf("Erreur: caractère non reconnu dans la map\n");
            exit(84);
    }
}

void print_map(int **map, int rows, int cols)
{
    char c;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            c = int_to_char(map[i][j]);
            printw("%c", c);
        }
        printw("\n");
    }
}

void proc_map(char *buffer, int ***map, MD dimensions, GameState *state)
{
    fill_map(buffer, map, dimensions, state);
    print_map(*map, dimensions.rows, dimensions.cols);
}
