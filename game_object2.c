/*
** EPITECH PROJECT, 2021
** game_object2.c
** File description:
** game_object2
*/

#include "my_runner.h"

game_object_t *create_game_object
(enum type_e type, sfVector2f pos, char *file)
{
    game_object_t *obj = malloc(sizeof(game_object_t));
    sfTexture *texture = sfTexture_createFromFile(file, NULL);
    sfSprite *sprite = sfSprite_create();

    obj->type = type;
    obj->pos = pos;
    obj->texture = texture;
    obj->sprite = sprite;
    obj->rect = create_rect(0, 0, 40, 40);
    obj->speed = 4.5;
    obj->id = -1;

    return obj;
}

void destroy_object2(game_object_t **obj)
{
    int i = 0;
    for (i = 0; obj[i]->type != null; i++) {
        sfSprite_destroy(obj[i]->sprite);
        sfTexture_destroy(obj[i]->texture);
        free(obj[i]);
    }
    sfSprite_destroy(obj[i]->sprite);
    sfTexture_destroy(obj[i]->texture);
    free(obj[i]);
    free(obj);
}

void apply_obj(sfRenderWindow *window, game_object_t *obj)
{
    if (is_in_screen(obj) == 1) {
        sfSprite_setTexture(obj->sprite, obj->texture, 0);
        sfSprite_setTextureRect(obj->sprite, obj->rect);
        sfSprite_setPosition(obj->sprite, obj->pos);
        sfRenderWindow_drawSprite(window, obj->sprite, NULL);
    }
}

void destroy_all_obj
(player_t *player, game_bg_t **bg, game_object_t **obj, sfClock *clock)
{
    destroy_player(player);
    destroy_background(bg);
    destroy_object2(obj);
    sfClock_destroy(clock);
}

void create_player3(player_t *player)
{
    sfSoundBuffer *buffer =
        sfSoundBuffer_createFromFile("sounds/effects/jump.ogg");
    sfSound *sound = sfSound_create();
    player->offset.microseconds = 162000;
    sfSound_setBuffer(sound, buffer);
    sfSound_setPlayingOffset(sound, player->offset);
    sfSound_setVolume(sound, 30);
    player->buffer = buffer;
    player->sound = sound;
    player->texture = player->plr_anim->run;
    player->last_time = 0;
    player->last_time_an = 0;
    sfSprite_scale(player->sprite, create_vectorf(3, 3));
}
