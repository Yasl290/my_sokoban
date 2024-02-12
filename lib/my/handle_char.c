/*
** EPITECH PROJECT, 2023
** B-PSU-100-LIL-1-1-sokoban-yanis.asselman
** File description:
** handle_char
*/

#include "include/my.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <ncurses.h>

void update_player_pos(GameState *state, MapParams *params)
{
    state->player.x = params->col;
    state->player.y = params->row;
}

void add_box_pos(GameState *state, MapParams *params)
{
    Position new_pos;

    new_pos.x = params->col;
    new_pos.y = params->row;
    state->boxes[state->box_count] = new_pos;
    state->box_count++;
}

void add_target_pos(GameState *state, MapParams *params)
{
    Position new_pos;

    new_pos.x = params->col;
    new_pos.y = params->row;
    state->targets[state->target_count] = new_pos;
    state->target_count++;
}

void handle_char(int val, int ***map, GameState *state, MapParams *params)
{
    (*map)[params->row][params->col] = val;
    if (val == 2) {
        update_player_pos(state, params);
    } else {
        handle_box_target(val, state, params);
    }
}

void handle_box_target(int val, GameState *state, MapParams *params)
{
    if (val == 0) {
        add_box_pos(state, params);
    } else if (val == 1) {
        add_target_pos(state, params);
    }
}
