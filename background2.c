/*
** EPITECH PROJECT, 2021
** background2.c
** File description:
** background2
*/

#include "my_runner.h"

void apply_bg(sfRenderWindow *window, game_bg_t *bg)
{
    sfSprite_setTexture(bg->sprite, bg->texture, 0);
    sfSprite_setTextureRect(bg->sprite, bg->rect);
    sfSprite_setPosition(bg->sprite, bg->pos);
    sfRenderWindow_drawSprite(window, bg->sprite, NULL);
}

void update_bg(game_bg_t *bg, sfClock *clock)
{
    move_rect(&bg->rect, bg->speed, 2560);
}
