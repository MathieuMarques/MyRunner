/*
** EPITECH PROJECT, 2022
** enemy.c
** File description:
** enemy
*/

#include "my_runner.h"

void spawn_enemy(game_object_t **obj)
{
    for (int i = 0; i < 10; i++) {
        if (obj[i]->pos.x < -40) {
            obj[i]->pos = create_vectorf(1800, -27);
            return;
        }
    }
}

void update_enemy(game_object_t **obj, sfClock *clock)
{
    int spawn = rand() % 90;
    if (spawn == 47)
        spawn_enemy(obj);
    for (int i = 0; i < 10; i++) {
        if (get_time_sec(clock) - obj[i]->last_time > 0.25) {
            move_rect(&obj[i]->rect, 40, 80);
            obj[i]->last_time = get_time_sec(clock);
        }
        if (obj[i]->pos.x > -80) {
            obj[i]->pos.x -= obj[i]->speed;
            physics_enemy(obj[i], obj);
        }
    }
}

void physics_enemy(game_object_t *obj, game_object_t **all_obj)
{
    obj->vel.y = obj->vel.y + 1.75;
    enemy_collide_x(obj, all_obj);
    obj->pos.y = obj->pos.y + obj->vel.y;
    enemy_collide_y(obj, all_obj);
}

int is_enemy_colliding(game_object_t *obj, game_object_t *obj2)
{
    sfVector2f pos = create_vectorf(obj2->pos.x + obj2->speed, obj2->pos.y);
    if (obj->pos.x < pos.x + obj2->rect.width &&
        obj->pos.x + obj->rect.width > pos.x &&
        obj->pos.y < obj2->pos.y + obj2->rect.height &&
        obj->pos.y + obj->rect.height > obj2->pos.y)
        return 1;
    else
        return 0;
}
