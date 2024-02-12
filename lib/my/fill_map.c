/*
** EPITECH PROJECT, 2023
** B-PSU-100-LIL-1-1-sokoban-yanis.asselman
** File description:
** fill_map
*/
#include "include/my.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <ncurses.h>

bool allocate_map_row(int ***map, int row, int cols)
{
    (*map)[row] = (int *)malloc(cols * sizeof(int));
    if (!(*map)[row]) {
        return false;
    }
    return true;
}

void free_allocated_rows(int ***map, int numRows)
{
    for (int i = 0; i < numRows; i++) {
        free((*map)[i]);
    }
    free(*map);
    *map = NULL;
}

void allocate_map_rows(int ***map, MD dimensions)
{
    for (int i = 0; i < dimensions.rows; i++) {
        if (!allocate_map_row(map, i, dimensions.cols)) {
            free_allocated_rows(map, i);
            my_printf("Memory allocation error for map row\n");
            exit(84);
        }
    }
}

void fill_map(const char *buffer, int ***map, MD dimensions, GameState *state)
{
    *map = (int **)malloc(dimensions.rows * sizeof(int *));
    if (dimensions.rows <= 0 || dimensions.cols <= 0) {
        my_printf("Invalid map dimensions\n");
        return;
    }
    if (!*map) {
        my_printf("Memory allocation error for map\n");
        exit(84);
    }
    allocate_map_rows(map, dimensions);
    m_ap(buffer, map, state, dimensions);
}
