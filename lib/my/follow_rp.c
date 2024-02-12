/*
** EPITECH PROJECT, 2023
** B-PSU-100-LIL-1-1-sokoban-yanis.asselman
** File description:
** gest
*/

#include "include/my.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <ncurses.h>


void prep(GD_T *gd, const char *fP, struct stat *fS, GC_T capacities)
{
    int rows = 0;
    int cols = 0;
    MD dimensions = {rows, cols};

    buf_er(gd->buffer, gd->fileDescriptor, fP, fS);
    calculate_dimensions(*(gd->buffer), &rows, &cols);
    init_game_state(gd->state, rows, cols, capacities);
    fill_map(*(gd->buffer), &(gd->map), dimensions, gd->state);
}

void process_and_release(GD_T *gd, MD dimensions)
{
    proc_map(*(gd->buffer), &(gd->map), dimensions, gd->state);
    free(gd->state->boxes);
    free(gd->state->targets);
    for (int i = 0; i < dimensions.rows; i++) {
        free(gd->map[i]);
    }
    free(gd->map);
    close(*(gd->fileDescriptor));
}

int gest(char **buffer, struct stat *fS, int *fileDescriptor, const char *fP)
{
    GameState state;
    int **map = NULL;
    GD_T gd = {buffer, fileDescriptor, &state, map};
    GC_T capacities = {10, 10};
    MD dimensions = {state.rows, state.cols};

    prep(&gd, fP, fS, capacities);
    process_and_release(&gd, dimensions);
    return 0;
}
