/*
** EPITECH PROJECT, 2023
** B-PSU-100-LIL-1-1-sokoban-yanis.asselman
** File description:
** pos_map
*/
#include "include/my.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <ncurses.h>

void init_game_state(GameState *state, int rows, int cols, GC_T capacities)
{
    state->boxes = malloc(sizeof(Position) * capacities.box_capacity);
    if (!state->boxes) {
        my_printf("Memory allocation error for boxes\n");
        exit(84);
    }
    state->targets = malloc(sizeof(Position) * capacities.target_capacity);
    if (!state->targets) {
        free(state->boxes);
        my_printf("Memory allocation error for targets\n");
        exit(84);
    }
    state->box_count = 0;
    state->target_count = 0;
    state->rows = rows;
    state->cols = cols;
}

int check_game_state(const int **map, const GameState *state)
{
    Position target;

    for (int i = 0; i < state->target_count; i++) {
        target = state->targets[i];
        if (map[target.y][target.x] != 0) {
            return 1;
        }
    }
    return 0;
}
