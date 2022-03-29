/*
** EPITECH PROJECT, 2022
** screen_game_over3.c
** File description:
** screen_game_over3
*/

#include "my_runner.h"

int check_pos_mouse_g_o
(sfRenderWindow* window, sfEvent event,
screen_game_over_t *g_o, all_game_obj_t *all)
{
    int ret = 0;
    if (event.mouseButton.x > g_o->button2->pos.x &&
    event.mouseButton.x < g_o->button2->pos.x + g_o->button2->rect.width &&
    event.mouseButton.y > g_o->button2->pos.y &&
    event.mouseButton.y < g_o->button2->pos.y + g_o->button2->rect.height) {
        destroy_all_obj(all->player, all->bg, all->obj, all->clock);
        sfMusic_destroy(all->music);
        free(all);
        destroy_g_o(g_o);
        sfRenderWindow_close(window);
        return 1;
    }
    ret = check_pos_mouse_g_o2(window, event, g_o, all);
    return ret;
}

int check_pos_mouse_g_o2
(sfRenderWindow *window, sfEvent event,
screen_game_over_t *g_o, all_game_obj_t *all)
{
    if (event.mouseButton.x > g_o->button1->pos.x &&
    event.mouseButton.x < g_o->button1->pos.x + g_o->button1->rect.width &&
    event.mouseButton.y > g_o->button1->pos.y &&
    event.mouseButton.y < g_o->button1->pos.y + g_o->button1->rect.height) {
        char *file = all->file;
        destroy_all_obj(all->player, all->bg, all->obj, all->clock);
        sfMusic_destroy(all->music);
        free(all);
        destroy_g_o(g_o);
        runner(window, event, file);
        return 1;
    }
    return 0;
}

int close_window_g_o
(sfRenderWindow *window, sfEvent event,
screen_game_over_t *g_o, all_game_obj_t *all)
{
    if (event.type == sfEvtClosed) {
        destroy_all_obj(all->player, all->bg, all->obj, all->clock);
        sfMusic_destroy(all->music);
        free(all);
        destroy_g_o(g_o);
        sfRenderWindow_close(window);
        return 1;
    }
    return 0;
}

void destroy_g_o(screen_game_over_t *g_o)
{
    destroy_title_obj(g_o->bg);
    destroy_title_obj(g_o->button1);
    destroy_title_obj(g_o->button2);
    destroy_title_obj(g_o->outline);
    sfSoundBuffer_destroy(g_o->sound->buffer);
    sfSound_destroy(g_o->sound->sound);
    sfMusic_stop(g_o->music);
    sfMusic_destroy(g_o->music);
    free(g_o);
}
