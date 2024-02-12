/*
** EPITECH PROJECT, 2023
** B-PSU-100-LIL-1-1-sokoban-yanis.asselman
** File description:
** file_rp
*/

#include "include/my.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <ncurses.h>

int file_rp(const char *fpth)
{
    int f;
    struct stat file_stat;
    char *buffer;

    if (stat(fpth, &file_stat) == -1) {
        my_printf("Error to get informations of the file\n");
        exit(84);
    }
    gest(&buffer, &file_stat, &f, fpth);
    return 0;
}
