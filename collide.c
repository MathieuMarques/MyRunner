/*
** EPITECH PROJECT, 2021
** collide.c
** File description:
** collide
*/

#include "my_runner.h"
#include "my.h"

int is_in_screen(game_object_t *obj)
{
    if (obj->pos.x < WIDTH && obj->pos.x + obj->rect.width > 0)
        return 1;
    else
        return 0;
}

void collide_x(player_t *player, game_object_t **obj)
{
    for (int i = 0; obj[i]->type != null; i++) {
        if (is_in_screen(obj[i])) {
            collide_x_2(player, obj, i);
        }
    }
    if (player->pos.x < 0)
        player->pos.x = 0;
    if (player->pos.x + player->hitbox.width > WIDTH)
        player->pos.x = WIDTH - player->hitbox.width;
}

void collide_y(player_t *player, game_object_t **obj)
{
    for (int i = 0; obj[i]->type != null; i++) {
        if (is_in_screen(obj[i])) {
            collide_y_2(player, obj, i);
        }
    }
}

int is_colliding(player_t *player, game_object_t *obj)
{
    sfVector2f pos = create_vectorf(obj->pos.x + obj->speed, obj->pos.y);
    if (player->pos.x < pos.x + obj->rect.width &&
        player->pos.x + player->hitbox.width > pos.x &&
        player->pos.y < obj->pos.y + obj->rect.height &&
        player->pos.y + player->hitbox.height > obj->pos.y)
        return 1;
    else
        return 0;
}

int is_on_ground(player_t *player, game_object_t **obj)
{
    int ret = 0;
    for (int i = 0; obj[i]->type != null; i++) {
        ret += is_on_ground_2(player, obj, i);
    }
    if (ret > 0)
        return 1;
    else
        return 0;
}
