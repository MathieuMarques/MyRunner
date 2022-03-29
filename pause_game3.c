/*
** EPITECH PROJECT, 2022
** pause_game3.c
** File description:
** pause_game3
*/

#include "my_runner.h"

int check_pos_mouse_pa
(sfRenderWindow* window, sfEvent event, pause_game_t *p)
{
    if (event.mouseButton.x > p->button1->pos.x &&
    event.mouseButton.x < p->button1->pos.x + p->button1->rect.width &&
    event.mouseButton.y > p->button1->pos.y &&
    event.mouseButton.y < p->button1->pos.y +
    p->button1->rect.height) {
        return 1;
    }
    if (event.mouseButton.x > p->button2->pos.x &&
    event.mouseButton.x < p->button2->pos.x + p->button2->rect.width &&
    event.mouseButton.y > p->button2->pos.y &&
    event.mouseButton.y < p->button2->pos.y +
    p->button2->rect.height) {
        sfRenderWindow_close(window);
        return 1;
    }
    return 0;
}

int check_input_pause
(sfRenderWindow *window, sfEvent event, pause_game_t *pause_g)
{
    if (event.type == sfEvtKeyPressed) {
        if (event.key.code == sfKeyEnter) {
            check_pos_outline_pa(window, event, pause_g);
            return 1;
        }
        if (event.key.code == sfKeyUp) {
            move_outline_pause(window, event, pause_g, -1);
        }
        if (event.key.code == sfKeyDown) {
            move_outline_pause(window, event, pause_g, 1);
        }
    }
    return 0;
}

void move_outline_pause
(sfRenderWindow *window, sfEvent event, pause_game_t *pause_g, int move)
{
    sfSound_stop(pause_g->sound->sound);
    sfSound_play(pause_g->sound->sound);
    pause_g->button += move;
    if (pause_g->button > 2)
        pause_g->button = 1;
    if (pause_g->button < 1)
        pause_g->button = 2;
    if (pause_g->button == 1)
        pause_g->outline->pos = pause_g->button1->pos;
    if (pause_g->button == 2)
        pause_g->outline->pos = pause_g->button2->pos;
}

void check_pos_outline_pa
(sfRenderWindow *window, sfEvent event, pause_game_t *pause_g)
{
    if (pause_g->button == 1) {
        return;
    }
    if (pause_g->button == 2) {
        sfRenderWindow_close(window);
        return;
    }
}
