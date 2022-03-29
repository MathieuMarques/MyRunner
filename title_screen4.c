/*
** EPITECH PROJECT, 2022
** title_screen4.c
** File description:
** title_screen4
*/

#include "my_runner.h"

void update_pose_mouse_ts1
(sfRenderWindow *window, sfEvent event, title_screen_t *title)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(window);
    if (mouse.x > title->button1->pos.x &&
    mouse.x < title->button1->pos.x + title->button1->rect.width &&
    mouse.y > title->button1->pos.y &&
    mouse.y < title->button1->pos.y + title->button1->rect.height) {
        if (title->button == 2) {
            sfSound_stop(title->sound->sound);
            sfSound_play(title->sound->sound);
            title->outline->pos = title->button1->pos;
            title->button = 1;
        }
    }
}

void update_pose_mouse_ts2
(sfRenderWindow *window, sfEvent event, title_screen_t *title)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(window);
    if (mouse.x > title->button2->pos.x &&
    mouse.x < title->button2->pos.x + title->button2->rect.width &&
    mouse.y > title->button2->pos.y &&
    mouse.y < title->button2->pos.y + title->button2->rect.height) {
        if (title->button == 1) {
            sfSound_stop(title->sound->sound);
            sfSound_play(title->sound->sound);
            title->outline->pos = title->button2->pos;
            title->button = 2;
        }
    }
}

void update_pose_mouse_ts
(sfRenderWindow *window, sfEvent event, title_screen_t *title)
{
    update_pose_mouse_ts1(window, event, title);
    update_pose_mouse_ts2(window, event, title);
}
