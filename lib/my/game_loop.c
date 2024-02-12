/*
** EPITECH PROJECT, 2023
** B-PSU-100-LIL-1-1-sokoban-yanis.asselman
** File description:
** game_loop
*/

#include "include/my.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <ncurses.h>
#include <stdbool.h>

struct stat allocate_buffer(char **buffer, const char *path)
{
    struct stat file_stat;

    if (stat(path, &file_stat) == -1) {
        my_printf("Erreur lors de l'obtention des informations du fichier\n");
        exit(84);
    }
    *buffer = malloc(file_stat.st_size + 1);
    if (*buffer == NULL) {
        my_printf("Erreur d'allocation mémoire\n");
        exit(84);
    }
    return file_stat;
}

static void prepare_game_state(char *buffer, GameState *state, int ***map)
{
    int rows;
    int cols;
    MD dimensions;
    GC_T capacities;

    calculate_dimensions(buffer, &rows, &cols);
    dimensions.rows = rows;
    dimensions.cols = cols;
    capacities.box_capacity = 10;
    capacities.target_capacity = 10;
    init_game_state(state, rows, cols, capacities);
    state->original_map = my_strdup(buffer);
    proc_map(buffer, map, dimensions, state);
}

void init_game(char **buffer, GameState *state, int ***map, const char *path)
{
    int f;
    struct stat file_stat = allocate_buffer(buffer, path);

    buf_er(buffer, &f, path, &file_stat);
    prepare_game_state(*buffer, state, map);
    close(f);
}

int check_game_status(int **map, GameState *state, int rows, int cols)
{
    if (game_over((const int **)map, state, rows, cols)) {
        return 1;
    }
    if (check_game_state((const int **)map, state) == 0) {
        clear();
        print_map((const int **)map, rows, cols);
        printw("Victoire ! Tous les 'O' sont remplacés.\n");
        refresh();
        usleep(2000000);
        return 0;
    }
    return -1;
}

static int evaluate_game_status(int move_result, GameContext *context)
{
    int game_status;

    if (move_result == 1) {
        game_status = check_game_status(
            context->map, context->state,
            context->rows, context->cols
        );
        if (game_status != -1) {
            return game_status;
        }
    }
    return -1;
}

static int handle_game_loop(int **map, GameState *state, int rows, int cols)
{
    int ch;
    int move_result;
    int game_status = -1;
    GameContext context = {map, state, rows, cols};

    do {
        clear();
        print_map(map, rows, cols);
        refresh();
        ch = getch();
        move_result = handle_movement(ch, &map, state);
        game_status = evaluate_game_status(move_result, &context);
        if (game_status != -1) {
            break;
        }
    } while (ch != 'q');
    return game_status;
}

int run_game_loop(int **map, GameState *state, int rows, int cols)
{
    int game_state;

    initscr();
    keypad(stdscr, TRUE);
    noecho();
    curs_set(0);
    game_state = handle_game_loop(map, state, rows, cols);
    endwin();
    return game_state;
}

int game_loop(char *argv[])
{
    int game_state;
    char *buffer = NULL;
    GameState state;
    int **map = NULL;

    init_game(&buffer, &state, &map, argv[1]);
    game_state = run_game_loop(map, &state, state.rows, state.cols);
    free_resources(&map, &state, state.rows);
    free(buffer);
    return game_state;
}
