/*
** EPITECH PROJECT, 2021
** event.c
** File description:
** event
*/

#include "my_runner.h"
#include "my.h"

void events(sfRenderWindow *window, sfEvent event, all_game_obj_t *all)
{
    sfVector2i mouse;
    while (sfRenderWindow_pollEvent(window, &event)) {
        close_window(window, event);
        check_pause(window, event, all);
        check_move(event, all->player);
    }
}

void close_window(sfRenderWindow *window, sfEvent event)
{
    if (event.type == sfEvtClosed)
        sfRenderWindow_close(window);
}

void check_pause(sfRenderWindow *window, sfEvent event, all_game_obj_t *all)
{
    if (event.type == sfEvtKeyPressed) {
        if (event.key.code == sfKeyEscape) {
            sfMusic_setVolume(all->music, 10);
            pause_game(window, event, all);
            wait_game(window, event, all);
            sfMusic_setVolume(all->music, 30);
        }
    }
}
