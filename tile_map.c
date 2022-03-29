/*
** EPITECH PROJECT, 2021
** tile_map.c
** File description:
** tile_map
*/

#include "my_runner.h"

game_object_t **create_tile_map(char *file)
{
    char *map = load_file(file);
    game_object_t **ground =
        malloc(sizeof(game_object_t *) * (count_game_objects(map) + 11));
    create_map_t map_id = create_map_struct();
    create_enemys(ground);
    for (map_id.index = 0; map[map_id.index] != '\0'; map_id.index++) {
        if (map[map_id.index] == '\n') {
            map_id.x = 0;
            map_id.y++;
        }
        place_tile(ground, &map_id, map);
        if (map[map_id.index] != '\n')
            map_id.x++;
    }
    ground[map_id.count] = create_game_object
        (null, create_vectorf(-1, -1), "sprites/bg/tile1.png");
    free(map);
    return ground;
}

create_map_t create_map_struct(void)
{
    create_map_t map_id;
    map_id.x = 0;
    map_id.y = 0;
    map_id.index = 0;
    map_id.count = 10;
    return map_id;
}

void move_rect(sfIntRect *rect, int offset, int max_value)
{
    if (rect->left + offset + rect->width > max_value)
        rect->left = 0;
    else
        rect->left += offset;
}

void move_tile(game_object_t **obj)
{
    for (int i = 0; obj[i]->type != null; i++) {
        if (!(obj[i]->pos.x + 40 < -120) && obj[i]->type != enemy)
            obj[i]->pos.x -= obj[i]->speed;
    }
}

void place_tile(game_object_t **obj, create_map_t *map_id, char *map)
{
    if (map[map_id->index] == '1') {
        obj[map_id->count] = create_game_object(block,
        create_vectorf(map_id->x * 40, map_id->y * 40),
        "sprites/bg/tile1.png");
        map_id->count++;
    }
    if (map[map_id->index] == '0') {
        obj[map_id->count] = create_game_object(block,
        create_vectorf(map_id->x * 40, map_id->y * 40),
        "sprites/bg/tile0.png");
        map_id->count++;
    }
    if (map[map_id->index] == '2') {
        obj[map_id->count] = create_game_object(spike,
        create_vectorf(map_id->x * 40, map_id->y * 40),
        "sprites/bg/spike.png");
        map_id->count++;
    }
    place_tile2(obj, map_id, map);
}
