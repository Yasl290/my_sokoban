/*
** EPITECH PROJECT, 2023
** B-PSU-100-LIL-1-1-sokoban-yanis.asselman
** File description:
** display_map
*/

#include "include/my.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <ncurses.h>

static void count_lines_in_buffer(const char *buffer, int *rows)
{
    for (int i = 0; buffer[i] != '\0'; i++) {
        if (buffer[i] == '\n' && buffer[i + 1] != '\0') {
            (*rows)++;
        }
    }
}

static void count_rows(const char *buffer, int *rows)
{
    *rows = 0;
    if (buffer[0] != '\0') {
        *rows = 1;
        count_lines_in_buffer(buffer, rows);
    }
}

static void update_max_cols(int current_length, int *cols)
{
    if (current_length > *cols) {
        *cols = current_length;
    }
}

static void max_col(const char *buffer, int *cols)
{
    int current_length = 0;

    *cols = 0;
    for (int i = 0; buffer[i] != '\0'; i++) {
        if (buffer[i] == '\n') {
            update_max_cols(current_length, cols);
            current_length = 0;
        } else {
            current_length++;
        }
    }
    update_max_cols(current_length, cols);
}

void calculate_dimensions(const char *buffer, int *rows, int *cols)
{
    count_rows(buffer, rows);
    max_col(buffer, cols);
}

int char_to_int(char c)
{
    switch (c) {
        case '#':
            return 3;
        case 'P':
            return 2;
        case ' ':
            return 5;
        case 'O':
            return 1;
        case 'X':
            return 0;
        default:
            return -1;
    }
}

static void loop_map(const char *buffer, int ***map, MapParams *params, int i)
{
    if (buffer[i] == '\n') {
        if (params->row + 1 < params->rows) {
            params->row++;
        }
        params->col = 0;
    } else {
        if (params->row < params->rows && params->col < params->cols) {
            (*map)[params->row][params->col] = char_to_int(buffer[i]);
        }
        params->col++;
    }
}

void m_ap(const char *buffer, int ***map, GameState *state, MD dim)
{
    int val;
    MapParams params = {0, 0, dim.rows, dim.cols};

    if (!map || !*map || !state) {
        my_printf("Erreur: Pointeur NULL détecté.\n");
        exit(84);
    }
    for (int i = 0; buffer[i] != '\0'; i++) {
        val = char_to_int(buffer[i]);
        if (buffer[i] != '\n') {
            (*map)[params.row][params.col] = val;
            update_game_state(val, state, &params);
            params.col++;
        } else {
            params.row++;
            params.col = 0;
        }
    }
}
