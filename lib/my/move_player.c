/*
** EPITECH PROJECT, 2023
** B-PSU-100-LIL-1-1-sokoban-yanis.asselman
** File description:
** move_player
*/

#include "include/my.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <ncurses.h>

void new_pos(Position *new_position, int direction, GameState *state)
{
    switch (direction) {
        case UP:
            new_position->y = state->player.y - 1;
            break;
        case DOWN:
            new_position->y = state->player.y + 1;
            break;
        case LEFT:
            new_position->x = state->player.x - 1;
            break;
        case RIGHT:
            new_position->x = state->player.x + 1;
            break;
    }
}

int move_box_if_needed(int ***map, GameState *state, Position new_position)
{
    int box_new_x;
    int box_new_y;

    if ((*map)[new_position.y][new_position.x] == 0) {
        box_new_x = new_position.x + (new_position.x - state->player.x);
        box_new_y = new_position.y + (new_position.y - state->player.y);
        if (box_new_x < 0 || box_new_x >= state->cols ||
            box_new_y < 0 || box_new_y >= state->rows ||
            (*map)[box_new_y][box_new_x] == 3) {
            return 0;
        }
        (*map)[new_position.y][new_position.x] = 5;
        (*map)[box_new_y][box_new_x] = 0;
        return 1;
    }
    return -1;
}

void player_pos(int ***map, GameState *state, Position new_position)
{
    (*map)[state->player.y][state->player.x] = 5;
    state->player = new_position;
    (*map)[new_position.y][new_position.x] = 2;
}

int move_player(int ***map, GameState *state, int direction)
{
    int box_moved;
    Position new_position = {state->player.x, state->player.y};

    new_pos(&new_position, direction, state);
    if (new_position.x < 0 || new_position.x >= state->cols ||
        new_position.y < 0 || new_position.y >= state->rows ||
        (*map)[new_position.y][new_position.x] == 3) {
        return 0;
    }
    box_moved = move_box_if_needed(map, state, new_position);
    if (box_moved == 0) {
        return 0;
    }
    player_pos(map, state, new_position);
    return 1;
}
