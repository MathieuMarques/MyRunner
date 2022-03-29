/*
** EPITECH PROJECT, 2021
** collide2.c
** File description:
** collide2
*/

#include "my_runner.h"

void collide_x_2(player_t *player, game_object_t **obj, int i)
{
    int cond = obj[i]->type != end && obj[i]->type != enemy;
    if (player->vel.x >= -obj[i]->speed &&
    is_colliding(player, obj[i]) == 1 && cond) {
        if (obj[i]->type == spike && player->invisibility == 0) {
            player->life--;
            player->invisibility = 60;
        }
        player->pos.x = obj[i]->pos.x - player->hitbox.width - 1;
    }
    if (player->vel.x < 0 && is_colliding(player, obj[i]) == 1 && cond) {
        if (obj[i]->type == spike && player->invisibility == 0) {
            player->life--;
            player->invisibility = 60;
        }
        player->pos.x = obj[i]->pos.x + obj[i]->rect.width + obj[i]->speed;
    }
    collide_x_3(player, obj, i);
}

void collide_y_2(player_t *player, game_object_t **obj, int i)
{
    int cond = obj[i]->type != end && obj[i]->type != enemy;
    if (player->vel.y >= 0 && is_colliding(player, obj[i]) == 1 && cond) {
        if (obj[i]->type == spike && player->invisibility == 0) {
            player->life--;
            player->invisibility = 60;
        }
        player->pos.y = obj[i]->pos.y - player->hitbox.height;
        player->vel.y = 0;
    }
    if (player->vel.y < 0 && is_colliding(player, obj[i]) == 1 && cond) {
        if (obj[i]->type == spike && player->invisibility == 0) {
            player->life--;
            player->invisibility = 60;
        }
        player->pos.y = obj[i]->pos.y + obj[i]->rect.height;
        player->vel.y = 0;
    }
    collide_y_3(player, obj, i);
}

int is_on_ground_2(player_t *player, game_object_t **obj, int i)
{
    sfVector2f pos =
    create_vectorf(obj[i]->pos.x + obj[i]->speed, obj[i]->pos.y);
    int cond = player->pos.x < pos.x + obj[i]->rect.width &&
    player->pos.x + player->hitbox.width - obj[i]->speed > pos.x &&
    player->pos.y < obj[i]->pos.y + obj[i]->rect.height &&
    player->pos.y + player->hitbox.height + 1 > obj[i]->pos.y;
    int cond2 = obj[i]->type != end && obj[i]->type != enemy;
    if (player->is_jumping == sfTrue && player->rect.left >= 90 &&
        cond && cond2) {
        return 1;
    } else if (player->is_jumping == sfFalse && cond) {
        return 1;
    }
    return 0;
}

void collide_x_3(player_t *player, game_object_t **obj, int i)
{
    if (obj[i]->type == end) {
        if (player->pos.x > obj[i]->pos.x) {
            player->win = 1;
            player->game_over = sfTrue;
        }
    }
    if (obj[i]->type == enemy && is_colliding(player, obj[i]) == 1 &&
        player->invisibility == 0) {
        player->life--;
        player->invisibility = 60;
    }
}

void collide_y_3(player_t *player, game_object_t **obj, int i)
{
    if (obj[i]->type == enemy && is_colliding(player, obj[i]) == 1 &&
        player->invisibility == 0) {
        player->life--;
        player->invisibility = 60;
    }
}
