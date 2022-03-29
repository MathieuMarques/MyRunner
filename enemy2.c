/*
** EPITECH PROJECT, 2022
** enemy2.c
** File description:
** enemy2
*/

#include "my_runner.h"

void enemy_collide_x(game_object_t *obj, game_object_t **all_obj)
{
    for (int i = 0; all_obj[i]->type != null; i++) {
        int cond = all_obj[i]->type != end && obj->id != all_obj[i]->id;
        int cond2 = all_obj[i]->type == enemy && all_obj[i]->pos.x > -40;
        int cond3 = all_obj[i]->type != enemy;
        if (is_enemy_colliding(obj, all_obj[i]) == 1 && cond && cond3 ||
            is_enemy_colliding(obj, all_obj[i]) == 1 && cond && cond2) {
            obj->pos.x =
            all_obj[i]->pos.x + all_obj[i]->rect.width + all_obj[i]->speed;
        }
    }
}

void enemy_collide_y(game_object_t *obj, game_object_t **all_obj)
{
    for (int i = 0; all_obj[i]->type != null; i++) {
        int cond = all_obj[i]->type != end && obj->id != all_obj[i]->id;
        int cond2 = all_obj[i]->type == enemy && all_obj[i]->pos.x > -40;
        int cond3 = all_obj[i]->type != enemy;
        if (is_enemy_colliding(obj, all_obj[i]) == 1 && cond && cond3 ||
            is_enemy_colliding(obj, all_obj[i]) == 1 && cond && cond2) {
            obj->pos.y = all_obj[i]->pos.y - obj->rect.height;
            obj->vel.y = 0;
        }
    }
}
