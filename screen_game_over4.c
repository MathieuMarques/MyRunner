/*
** EPITECH PROJECT, 2022
** screen_game_over4.c
** File description:
** screen_game_over4
*/

#include "my_runner.h"

void apply_game_over
(sfRenderWindow *window, player_t *player, screen_game_over_t *g_o)
{
    sfSprite_setTexture(g_o->bg->sprite, g_o->bg->texture, 0);
    sfSprite_setTextureRect(g_o->bg->sprite, g_o->bg->rect);
    sfSprite_setPosition(g_o->bg->sprite, g_o->bg->pos);
    sfRenderWindow_drawSprite(window, g_o->bg->sprite, NULL);
    sfSprite_setTexture(g_o->button1->sprite, g_o->button1->texture, 0);
    sfSprite_setTextureRect(g_o->button1->sprite, g_o->button1->rect);
    sfSprite_setPosition(g_o->button1->sprite, g_o->button1->pos);
    sfRenderWindow_drawSprite(window, g_o->button1->sprite, NULL);
    sfSprite_setTexture(g_o->button2->sprite, g_o->button2->texture, 0);
    sfSprite_setTextureRect(g_o->button2->sprite, g_o->button2->rect);
    sfSprite_setPosition(g_o->button2->sprite, g_o->button2->pos);
    sfRenderWindow_drawSprite(window, g_o->button2->sprite, NULL);
    sfSprite_setTexture(g_o->outline->sprite, g_o->outline->texture, 0);
    sfSprite_setTextureRect(g_o->outline->sprite, g_o->outline->rect);
    sfSprite_setPosition(g_o->outline->sprite, g_o->outline->pos);
    sfRenderWindow_drawSprite(window, g_o->outline->sprite, NULL);
    sfRenderWindow_drawText(window, player->score->text, NULL);
    sfRenderWindow_drawText(window, player->score->text_score, NULL);
}

void update_pose_mouse_g_o
(sfRenderWindow *window, sfEvent event, screen_game_over_t *g_o)
{
    update_pose_mouse_g_o1(window, event, g_o);
    update_pose_mouse_g_o2(window, event, g_o);
}

void update_pose_mouse_g_o1
(sfRenderWindow *window, sfEvent event, screen_game_over_t *g_o)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(window);
    if (mouse.x > g_o->button1->pos.x &&
    mouse.x < g_o->button1->pos.x + g_o->button1->rect.width &&
    mouse.y > g_o->button1->pos.y &&
    mouse.y < g_o->button1->pos.y + g_o->button1->rect.height) {
        if (g_o->button == 2) {
            sfSound_stop(g_o->sound->sound);
            sfSound_play(g_o->sound->sound);
            g_o->outline->pos = g_o->button1->pos;
            g_o->button = 1;
        }
    }
}

void update_pose_mouse_g_o2
(sfRenderWindow *window, sfEvent event, screen_game_over_t *g_o)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(window);
    if (mouse.x > g_o->button2->pos.x &&
    mouse.x < g_o->button2->pos.x + g_o->button2->rect.width &&
    mouse.y > g_o->button2->pos.y &&
    mouse.y < g_o->button2->pos.y + g_o->button2->rect.height) {
        if (g_o->button == 1) {
            sfSound_stop(g_o->sound->sound);
            sfSound_play(g_o->sound->sound);
            g_o->outline->pos = g_o->button2->pos;
            g_o->button = 2;
        }
    }
}
