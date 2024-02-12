/*
** EPITECH PROJECT, 2023
** B-MUL-100-LIL-1-1-myhunter-yanis.asselman
** File description:
** starting_hunter
*/
#include "include/struct.h"
#include "include/my.h"
#include <stdbool.h>

bool if_play(GLOBAL_T *ALL)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(WIND);

    if (mouse.x >= IMG[1].pos.x && mouse.x <= IMG[1].pos.x + 400 &&
        mouse.y >= IMG[1].pos.y && mouse.y <= IMG[1].pos.y + 250 &&
        EVENT.type == sfEvtMouseButtonPressed) {
        return true;
    }
    return false;
}

void window_event(GLOBAL_T *ALL)
{
    if (EVENT.type == sfEvtClosed) {
                sfRenderWindow_close(WIND);
                }
}

void handle_menu_events(GLOBAL_T *ALL, bool *startGame)
{
    while (sfRenderWindow_pollEvent(WIND, &EVENT)) {
        window_event(ALL);
        if (EVENT.type == sfEvtMouseButtonPressed) {
            *startGame = if_play(ALL);
        }
    }
}

void window_menu(GLOBAL_T *ALL)
{
    bool startGame = false;

    sfWindow_setFramerateLimit((sfWindow*)WIND, 60);
    while (sfRenderWindow_isOpen(WIND)) {
        handle_menu_events(ALL, &startGame);
        if (startGame) {
            game_inti(ALL);
            break;
        }
        sfRenderWindow_clear(WIND, sfBlack);
        for (int i = 0; i < 2; i++) {
            sfRenderWindow_drawSprite(WIND, ALL->pics[i].sprite, NULL);
        }
        sfSound_play(ALL->son.ost);
        sfRenderWindow_display(WIND);
    }
}
