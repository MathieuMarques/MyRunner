/*
** EPITECH PROJECT, 2021
** game_object.c
** File description:
** game_object
*/

#include "my_runner.h"

player_t *create_player(void)
{
    player_t *player = malloc(sizeof(player_t));
    plr_anim_t *plr_anim = malloc(sizeof(plr_anim_t));
    sfTexture *run = sfTexture_createFromFile("sprites/knightrun.png", NULL);
    sfTexture *jump = sfTexture_createFromFile("sprites/knightjump.png", NULL);
    sfTexture *run_t =
    sfTexture_createFromFile("sprites/knightrun_t.png", NULL);
    sfTexture *jump_t =
    sfTexture_createFromFile("sprites/knightjump_t.png", NULL);
    sfSprite *sprite = sfSprite_create();
    if (sprite == NULL || run == NULL || jump == NULL ||
        jump_t == NULL || run_t == NULL)
        return NULL;
    player->sprite = sprite;
    plr_anim->run = run;
    plr_anim->jump = jump;
    plr_anim->run_t = run_t;
    plr_anim->jump_t = jump_t;
    player->plr_anim = plr_anim;
    create_player2(player);
    return player;
}

void create_player2(player_t *player)
{
    player->pos = create_vectorf(585, 305);
    player->rect = create_rect(0, 0, 30, 30);
    player->hitbox = create_rect(0, 0, 17 * 3, 29 * 3);
    player->vel = create_vectorf(0, 0);
    player->move.right = sfFalse;
    player->move.left = sfFalse;
    player->move.jump = sfFalse;
    player->is_jumping = sfFalse;
    player->anim = anim_run;
    player->game_over = sfFalse;
    player->score = create_plr_text();
    player->life = 2;
    player->invisibility = 0;
    player->win = 0;
    create_player3(player);
}

game_bg_t *create_bg
(float speed, char *path, sfIntRect rect, sfIntRect hitbox)
{
    game_bg_t *bg = malloc(sizeof(game_bg_t));
    sfTexture *texture = sfTexture_createFromFile(path, NULL);
    sfSprite *sprite = sfSprite_create();
    if (sprite == NULL || texture == NULL)
        return NULL;
    bg->sprite = sprite;
    bg->texture = texture;
    bg->hitbox = hitbox;
    bg->pos = create_vectorf(0, 0);
    bg->rect = rect;
    bg->speed = speed;
}

void destroy_object(game_bg_t *obj)
{
    sfSprite_destroy(obj->sprite);
    sfTexture_destroy(obj->texture);
    free(obj);
}

void destroy_player(player_t *player)
{
    sfSprite_destroy(player->sprite);
    sfTexture_destroy(player->texture);
    sfFont_destroy(player->score->font);
    sfText_destroy(player->score->text);
    sfText_destroy(player->score->text_score);
    sfText_destroy(player->score->life);
    sfText_destroy(player->score->life_nb);
    sfSoundBuffer_destroy(player->buffer);
    sfSound_destroy(player->sound);
    free(player->score);
    free(player->plr_anim);
    free(player);
}
