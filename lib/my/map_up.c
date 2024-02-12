/*
** EPITECH PROJECT, 2023
** B-PSU-100-LIL-1-1-sokoban-yanis.asselman
** File description:
** map_up
*/

#include "include/my.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <ncurses.h>


void buff(const char *buffer, int ***map, GameState *state, MapParams *params)
{
    int val;

    for (int i = 0; buffer[i] != '\0'; i++) {
        val = char_to_int(buffer[i]);
        handle_char(val, map, state, params);
        update_position(buffer[i], params);
    }
}

void update_position(char c, MapParams *params)
{
    if (c != '\n') {
        params->col++;
    } else {
        params->row++;
        params->col = 0;
    }
}

void handle_val_zero_and_one(int val, GameState *state, Position newPos)
{
    if (val == 0) {
        state->boxes[state->box_count] = newPos;
        state->box_count++;
    } else if (val == 1) {
        state->targets[state->target_count] = newPos;
        state->target_count++;
    }
}

void update_game_state(int val, GameState *state, MapParams *params)
{
    Position newPos;

    if (val == 2) {
        state->player.x = params->col;
        state->player.y = params->row;
    } else {
        newPos = (Position){params->col, params->row};
        handle_val_zero_and_one(val, state, newPos);
    }
}
