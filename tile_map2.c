/*
** EPITECH PROJECT, 2022
** tile_map2.c
** File description:
** tile_map2
*/

#include "my_runner.h"

void place_tile2(game_object_t **obj, create_map_t *map_id, char *map)
{
    if (map[map_id->index] == 'e') {
        obj[map_id->count] = create_end(end,
        create_vectorf(map_id->x * 40, 0), "sprites/bg/end.png");
        map_id->count++;
    }
}

game_object_t *create_end
(enum type_e type, sfVector2f pos, char *file)
{
    game_object_t *obj = malloc(sizeof(game_object_t));
    sfTexture *texture = sfTexture_createFromFile(file, NULL);
    sfSprite *sprite = sfSprite_create();

    obj->type = type;
    obj->pos = pos;
    obj->texture = texture;
    obj->sprite = sprite;
    obj->rect = create_rect(0, 0, 40, 720);
    obj->speed = 4.5;

    return obj;
}

game_object_t *create_enemy_obj
(enum type_e type, sfVector2f pos, char *file, int id)
{
    game_object_t *obj = malloc(sizeof(game_object_t));
    sfTexture *texture = sfTexture_createFromFile(file, NULL);
    sfSprite *sprite = sfSprite_create();

    obj->type = type;
    obj->pos = pos;
    obj->texture = texture;
    obj->sprite = sprite;
    obj->rect = create_rect(0, 0, 40, 27);
    obj->speed = 5.5;
    obj->vel = create_vectorf(0, 0);
    obj->last_time = 0.0;
    obj->id = id;

    return obj;
}

void create_enemys(game_object_t **obj)
{
    for (int i = 0; i < 10; i++) {
        obj[i] =
        create_enemy_obj
            (enemy, create_vectorf(-80, 500), "sprites/slime.png", i);
    }
}
