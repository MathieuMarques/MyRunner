/*
** EPITECH PROJECT, 2022
** pause_game4.c
** File description:
** pause_game4
*/

#include "my_runner.h"

void apply_cd2(sfRenderWindow *window, wait_game_t *wait_game, sfClock *clock)
{
    float time = get_time_sec(clock);
    if (time > 2) {
        sfSprite_setTexture
        (wait_game->one->sprite, wait_game->one->texture, 0);
        sfSprite_setTextureRect(wait_game->one->sprite, wait_game->one->rect);
        sfSprite_setPosition(wait_game->one->sprite, wait_game->one->pos);
        sfRenderWindow_drawSprite(window, wait_game->one->sprite, NULL);
    }
}

void apply_cd(sfRenderWindow *window, wait_game_t *wait_game, sfClock *clock)
{
    float time = get_time_sec(clock);
    if (time <= 1 && time >= 0) {
        sfSprite_setTexture
        (wait_game->three->sprite, wait_game->three->texture, 0);
        sfSprite_setTextureRect
        (wait_game->three->sprite, wait_game->three->rect);
        sfSprite_setPosition(wait_game->three->sprite, wait_game->three->pos);
        sfRenderWindow_drawSprite(window, wait_game->three->sprite, NULL);
    }
    if (time > 1 && time <= 2) {
        sfSprite_setTexture
        (wait_game->two->sprite, wait_game->two->texture, 0);
        sfSprite_setTextureRect(wait_game->two->sprite, wait_game->two->rect);
        sfSprite_setPosition(wait_game->two->sprite, wait_game->two->pos);
        sfRenderWindow_drawSprite(window, wait_game->two->sprite, NULL);
    }
    apply_cd2(window, wait_game, clock);
}
