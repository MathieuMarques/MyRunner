/*
** EPITECH PROJECT, 2021
** background.c
** File description:
** background
*/

#include "my_runner.h"

game_bg_t **create_all_layer(void)
{
    game_bg_t **bg = malloc(12 * sizeof(game_bg_t));
    sfIntRect hitbox = create_rect(0, 0, 0, 0);
    bg[0] = create_bg(5, "sprites/bg/bg_layer1.png",
    create_rect(0, 0, 1280, 720), hitbox);
    bg[1] = create_bg(5, "sprites/bg/bg_layer2.png",
    create_rect(0, 0, 1280, 720), hitbox);
    bg[2] = create_bg(5, "sprites/bg/bg_layer4.png",
    create_rect(0, 0, 1280, 720), hitbox);
    bg[3] = create_bg(5, "sprites/bg/bg_layer5.png",
    create_rect(0, 0, 1280, 720), hitbox);
    bg[4] = create_bg(4.5, "sprites/bg/bg_layer3.png",
    create_rect(0, 0, 1280, 720), hitbox);
    create_all_layer2(bg);
    return bg;
}

void create_all_layer2(game_bg_t **bg)
{
    sfIntRect hitbox = create_rect(0, 0, 0, 0);
    bg[5] = create_bg(4, "sprites/bg/bg_layer8.png",
    create_rect(0, 0, 1280, 720), hitbox);
    bg[6] = create_bg(3, "sprites/bg/bg_layer9.png",
    create_rect(0, 0, 1280, 720), hitbox);
    bg[7] = create_bg(2, "sprites/bg/bg_layer10.png",
    create_rect(0, 0, 1280, 720), hitbox);
    bg[8] = create_bg(0, "sprites/bg/bg_layer11.png",
    create_rect(0, 0, 1280, 720), hitbox);
    bg[9] = create_bg(0, "sprites/bg/bg_layer12.png",
    create_rect(0, 0, 1280, 720), hitbox);
    bg[10] = create_bg(0, "sprites/bg/void.png",
    create_rect(0, 0, 1280, 720), hitbox);
}

void destroy_background(game_bg_t **bg)
{
    for (int i = 0; i < 10; i++) {
        destroy_object(bg[i]);
    }
    free(bg);
}

void update_all_bg(game_bg_t **bg, sfClock *clock)
{
    for (int i = 0; i < 10; i++) {
        update_bg(bg[i], clock);
    }
}
