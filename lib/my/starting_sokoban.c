/*
** EPITECH PROJECT, 2023
** B-PSU-100-LIL-1-1-sokoban-yanis.asselman
** File description:
** starting_sokoban
*/

#include "include/my.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <ncurses.h>
#include <stdbool.h>

void free_map_row(int **map_row)
{
    if (map_row) {
        free(map_row);
    }
}

void free_map(int ***map, int rows)
{
    if (map) {
        for (int i = 0; i < rows; i++) {
            free_map_row((*map)[i]);
        }
        free(*map);
    }
}

void free_resources(int ***map, GameState *state, int rows)
{
    free_map(map, rows);
    if (state) {
        if (state->boxes) {
            free(state->boxes);
        }
        if (state->targets) {
            free(state->targets);
        }
        if (state->original_map) {
            free(state->original_map);
        }
    }
}

bool game_over(const int **map, GameState *state, int rows, int cols)
{
    bool is_blocked;
    Position box;

    for (int i = 0; i < state->box_count; i++) {
        box = state->boxes[i];
        is_blocked = true;
        if ((box.y > 0 && map[box.y - 1][box.x] == 5) ||
            (box.y < rows - 1 && map[box.y + 1][box.x] == 5) ||
            (box.x > 0 && map[box.y][box.x - 1] == 5) ||
            (box.x < cols - 1 && map[box.y][box.x + 1] == 5)) {
            is_blocked = false;
        }
        if (!is_blocked) {
            return false;
        }
    }
    return true;
}
