/*
** EPITECH PROJECT, 2022
** window2.c
** File description:
** window2
*/

#include "my_runner.h"

void update_all
(player_t *player, game_object_t **obj, game_bg_t **bg, sfClock *clock)
{
    update_enemy(obj, clock);
    move_tile(obj);
    update_player(player, obj, clock);
    update_all_bg(bg, clock);
}

sfMusic *create_music_game(void)
{
    sfMusic *music = sfMusic_createFromFile("sounds/music/bg_game.ogg");
    sfMusic_setLoop(music, sfTrue);
    sfMusic_setVolume(music, 30);
    sfMusic_play(music);
    return music;
}

all_game_obj_t *create_all_obj(char *file)
{
    all_game_obj_t *all = malloc(sizeof(all_game_obj_t));
    all->file = file;
    all->obj = create_tile_map(file);
    all->player = create_player();
    all->bg = create_all_layer();
    all->music = create_music_game();
    all->clock = sfClock_create();
    return all;
}
