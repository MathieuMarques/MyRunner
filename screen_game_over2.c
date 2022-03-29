/*
** EPITECH PROJECT, 2022
** screen_game_over2.c
** File description:
** screen_game_over2
*/

#include "my_runner.h"

int game_over_event
(sfRenderWindow *window, sfEvent event,
screen_game_over_t *g_o, all_game_obj_t *all)
{
    int ret = 0;
    while (sfRenderWindow_pollEvent(window, &event)) {
        ret += close_window_g_o(window, event, g_o, all);
        ret += check_mouse_g_o(window, event, g_o, all);
        ret += check_input_g_o(window, event, g_o, all);
    }
    return ret;
}

void move_outline_g_o(screen_game_over_t *g_o, int move)
{
    sfSound_stop(g_o->sound->sound);
    sfSound_play(g_o->sound->sound);
    g_o->button += move;
    if (g_o->button > 2)
        g_o->button = 1;
    if (g_o->button < 1)
        g_o->button = 2;
    if (g_o->button == 1)
        g_o->outline->pos = g_o->button1->pos;
    if (g_o->button == 2)
        g_o->outline->pos = g_o->button2->pos;
}

void check_pos_outline_g_o
(sfRenderWindow *window, sfEvent event,
screen_game_over_t *g_o, all_game_obj_t *all)
{
    if (g_o->button == 1) {
        char *file = all->file;
        destroy_all_obj(all->player, all->bg, all->obj, all->clock);
        sfMusic_destroy(all->music);
        free(all);
        destroy_g_o(g_o);
        runner(window, event, file);
        return;
    }
    if (g_o->button == 2) {
        destroy_all_obj(all->player, all->bg, all->obj, all->clock);
        sfMusic_destroy(all->music);
        free(all);
        destroy_g_o(g_o);
        sfRenderWindow_close(window);
        return;
    }
}

int check_input_g_o
(sfRenderWindow *window, sfEvent event,
screen_game_over_t *g_o, all_game_obj_t *all)
{
    if (event.type == sfEvtKeyPressed) {
        if (event.key.code == sfKeyEnter) {
            check_pos_outline_g_o(window, event, g_o, all);
            return 1;
        }
        if (event.key.code == sfKeyUp) {
            move_outline_g_o(g_o, -1);
        }
        if (event.key.code == sfKeyDown) {
            move_outline_g_o(g_o, 1);
        }
    }
    return 0;
}

int check_mouse_g_o
(sfRenderWindow *window, sfEvent event,
screen_game_over_t *g_o, all_game_obj_t *all)
{
    update_pose_mouse_g_o(window, event, g_o);
    if (event.type == sfEvtMouseButtonPressed) {
        if (event.key.code == sfMouseLeft)
            return check_pos_mouse_g_o(window, event, g_o, all);
    }
    return 0;
}
