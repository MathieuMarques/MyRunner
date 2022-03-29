/*
** EPITECH PROJECT, 2022
** player3.c
** File description:
** player3
*/

#include "my_runner.h"

void change_sprite(player_t *player)
{
    if (player->invisibility > 0) {
        if (player->anim == anim_jump) {
            player->anim = anim_jump_tr;
            player->texture = player->plr_anim->jump_t;
        }
        if (player->anim == anim_run) {
            player->anim = anim_run_tr;
            player->texture = player->plr_anim->run_t;
        }
    }
    change_sprite3(player);
    change_sprite2(player);
}

void change_sprite2(player_t *player)
{
    if (player->invisibility > 0) {
        if (player->anim == fall) {
            player->anim = fall_tr;
            player->texture = player->plr_anim->jump_t;
        }
    }
    if (player->invisibility == 0) {
        if (player->anim == fall_tr) {
            player->anim = fall;
            player->texture = player->plr_anim->jump;
        }
    }
}

void change_sprite3(player_t *player)
{
    if (player->invisibility == 0) {
        if (player->anim == anim_jump_tr) {
            player->anim = anim_jump;
            player->texture = player->plr_anim->jump;
        }
        if (player->anim == anim_run_tr) {
            player->anim = anim_run;
            player->texture = player->plr_anim->run;
        }
    }
}

int is_game_over2(player_t *player, game_object_t **obj, int i)
{
    if (is_in_screen(obj[i])) {
        if (player->pos.x - 2 < 0 && is_colliding(player, obj[i]) == 1
        && obj[i]->type != end && obj[i]->type != enemy) {
            player->game_over = sfTrue;
            return 1;
        }
    }
    return 0;
}

void update_score(player_t *player, sfClock *clock)
{
    player->last_time = get_time_sec(clock);
    if (player->move.right == sfTrue && player->move.left == sfFalse)
        player->score->score += 8;
    else
        player->score->score += 5;
}
