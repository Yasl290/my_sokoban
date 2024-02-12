/*
** EPITECH PROJECT, 2023
** B-PSU-100-LIL-1-1-sokoban-yanis.asselman
** File description:
** move_elements
*/

#include "include/my.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <ncurses.h>

int handle_movement(int ch, int ***map, GameState *state)
{
    int move_result = 0;

    switch (ch) {
        case KEY_UP:
            move_result = move_player(map, state, UP);
            break;
        case KEY_DOWN:
            move_result = move_player(map, state, DOWN);
            break;
        case KEY_LEFT:
            move_result = move_player(map, state, LEFT);
            break;
        case KEY_RIGHT:
            move_result = move_player(map, state, RIGHT);
            break;
        default:
            break;
    }
    return move_result;
}

int is_box_blocked(const int **map, Position box, int rows, int cols)
{
    int x = box.x;
    int y = box.y;
    int horizontal;
    int vertical;

    horizontal = ((x == 0 || map[y][x - 1] == 3 || map[y][x - 1] == 0) &&
    (x == cols - 1 || map[y][x + 1] == 3 || map[y][x + 1] == 0));
    vertical = ((y == 0 || map[y - 1][x] == 3 || map[y - 1][x] == 0) &&
    (y == rows - 1 || map[y + 1][x] == 3 || map[y + 1][x] == 0));
    return horizontal || vertical;
}
