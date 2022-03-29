/*
** EPITECH PROJECT, 2021
** player2.c
** File description:
** player2
*/

#include "my_runner.h"

void move(player_t *player, game_object_t **obj)
{
    float friction = 0.25;
    float acc = 0;
    if (player->move.right == sfTrue)
        acc += MOVE_SPEED;
    if (player->move.left == sfTrue)
        acc -= MOVE_SPEED;
    if (player->move.jump == sfTrue)
        jump(player, obj);
    acc += player->vel.x * -friction;
    player->vel.x += acc;
}

void update_player_anim(player_t *player, game_object_t **obj, sfClock *clock)
{
    int cond_anim =
                (player->anim == anim_jump || player->anim == anim_jump_tr ||
                player->anim == fall || player->anim == fall_tr)
                && player->rect.left == 210;
    int cond2 = is_on_ground(player, obj) == 0 && cond_anim;
    if (is_on_ground(player, obj) == 1) {
        player->is_jumping = sfFalse;
    }
    if (is_on_ground(player, obj) == 1 && cond_anim) {
        player->texture = player->plr_anim->run;
        player->rect.left = 0;
        player->anim = anim_run;
    }
    if (cond2) {
        player->anim = fall;
    }
    player_anim(player, clock);
}

void player_anim(player_t *player, sfClock *clock)
{
    if (player->anim == fall)
        return;
    if (player->anim == anim_jump) {
        if (get_time_sec(clock) - player->last_time_an > 0.06) {
            move_rect(&player->rect, 30, 300);
            player->last_time_an = get_time_sec(clock);
        }
        return;
    }
    if (player->move.right == 1) {
        if (get_time_sec(clock) - player->last_time_an > 0.05) {
            move_rect(&player->rect, 30, 240);
            player->last_time_an = get_time_sec(clock);
        }
    } else if (get_time_sec(clock) - player->last_time_an > 0.1) {
        move_rect(&player->rect, 30, 240);
        player->last_time_an = get_time_sec(clock);
    }
}

void update_player(player_t *player, game_object_t **obj, sfClock *clock)
{
    update_pos(player, obj, clock);
    update_player_anim(player, obj, clock);
}

int is_game_over(player_t *player, game_object_t **obj)
{
    for (int i = 0; obj[i]->type != null; i++) {
        if (is_game_over2(player, obj, i) == 1)
            return 1;
    }
    if (player->pos.y > HEIGHT) {
        player->game_over = sfTrue;
        return 1;
    }
    return 0;
}
