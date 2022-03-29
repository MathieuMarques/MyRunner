/*
** EPITECH PROJECT, 2021
** player.c
** File description:
** player
*/

#include "my_runner.h"
#include "my.h"

void check_move(sfEvent event, player_t *player)
{
    if (event.type == sfEvtKeyPressed) {
        if (event.key.code == sfKeyRight)
            player->move.right = sfTrue;
        if (event.key.code == sfKeyLeft)
            player->move.left = sfTrue;
        if (event.key.code == sfKeySpace)
            player->move.jump = sfTrue;
    }
    if (event.type == sfEvtKeyReleased) {
        if (event.key.code == sfKeyRight)
            player->move.right = sfFalse;
        if (event.key.code == sfKeyLeft)
            player->move.left = sfFalse;
        if (event.key.code == sfKeySpace)
            player->move.jump = sfFalse;
    }
}

void jump(player_t *player, game_object_t **obj)
{
    if (is_on_ground(player, obj) == 1) {
        player->is_jumping = sfTrue;
        player->vel.y = -JUMP_HEIGHT;
        player->texture = player->plr_anim->jump;
        player->rect.left = 0;
        player->anim = anim_jump;
        sfSound_stop(player->sound);
        sfSound_setPlayingOffset(player->sound, player->offset);
        sfSound_play(player->sound);
    }
}

void physics(player_t *player, game_object_t **obj)
{
    player->vel.y = player->vel.y + 1.75;
    player->pos.x = player->pos.x + player->vel.x;
    collide_x(player, obj);
    player->pos.y = player->pos.y + player->vel.y;
    collide_y(player, obj);
}

void update_pos(player_t *player, game_object_t **obj, sfClock *clock)
{
    if (get_time_sec(clock) - player->last_time > 1 / FPS) {
        if (is_game_over(player, obj) == 0) {
            move(player, obj);
            physics(player, obj);
            update_score(player, clock);
        }
        if (player->life == 0) {
            player->game_over = sfTrue;
        }
        if (player->invisibility > 0) {
            change_sprite(player);
            player->invisibility--;
        }
        if (player->invisibility == 0) {
            change_sprite(player);
        }
    }
}
