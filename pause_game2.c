/*
** EPITECH PROJECT, 2022
** pause_game2.c
** File description:
** pause_game2
*/

#include "my_runner.h"

void apply_pause_obj(sfRenderWindow *window, pause_game_t *pause_g)
{
    sfSprite_setTexture(pause_g->bg->sprite, pause_g->bg->texture, 0);
    sfSprite_setTextureRect(pause_g->bg->sprite, pause_g->bg->rect);
    sfSprite_setPosition(pause_g->bg->sprite, pause_g->bg->pos);
    sfRenderWindow_drawSprite(window, pause_g->bg->sprite, NULL);
    sfSprite_setTexture(pause_g->button1->sprite, pause_g->button1->texture, 0);
    sfSprite_setTextureRect(pause_g->button1->sprite, pause_g->button1->rect);
    sfSprite_setPosition(pause_g->button1->sprite, pause_g->button1->pos);
    sfRenderWindow_drawSprite(window, pause_g->button1->sprite, NULL);
    sfSprite_setTexture(pause_g->button2->sprite, pause_g->button2->texture, 0);
    sfSprite_setTextureRect(pause_g->button2->sprite, pause_g->button2->rect);
    sfSprite_setPosition(pause_g->button2->sprite, pause_g->button2->pos);
    sfRenderWindow_drawSprite(window, pause_g->button2->sprite, NULL);
    sfSprite_setTexture(pause_g->outline->sprite, pause_g->outline->texture, 0);
    sfSprite_setTextureRect(pause_g->outline->sprite, pause_g->outline->rect);
    sfSprite_setPosition(pause_g->outline->sprite, pause_g->outline->pos);
    sfRenderWindow_drawSprite(window, pause_g->outline->sprite, NULL);
}

void destroy_pause(pause_game_t *pause_g)
{
    destroy_title_obj(pause_g->bg);
    destroy_title_obj(pause_g->button1);
    destroy_title_obj(pause_g->button2);
    destroy_title_obj(pause_g->outline);
    sfSoundBuffer_destroy(pause_g->sound->buffer);
    sfSound_destroy(pause_g->sound->sound);
    free(pause_g);
}

int check_mouse_pause
(sfRenderWindow *window, sfEvent event, pause_game_t *pause_g)
{
    update_pose_mouse_pa1(window, event, pause_g);
    update_pose_mouse_pa2(window, event, pause_g);
    if (event.type == sfEvtMouseButtonPressed) {
        if (event.key.code == sfMouseLeft) {
            return check_pos_mouse_pa(window, event, pause_g);
        }
    }
    return 0;
}

void update_pose_mouse_pa1
(sfRenderWindow *window, sfEvent event, pause_game_t *pause_g)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(window);
    if (mouse.x > pause_g->button1->pos.x &&
    mouse.x < pause_g->button1->pos.x + pause_g->button1->rect.width &&
    mouse.y > pause_g->button1->pos.y &&
    mouse.y < pause_g->button1->pos.y + pause_g->button1->rect.height) {
        if (pause_g->button == 2) {
            sfSound_stop(pause_g->sound->sound);
            sfSound_play(pause_g->sound->sound);
            pause_g->outline->pos = pause_g->button1->pos;
            pause_g->button = 1;
        }
    }
}

void update_pose_mouse_pa2
(sfRenderWindow *window, sfEvent event, pause_game_t *pause_g)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(window);
    if (mouse.x > pause_g->button2->pos.x &&
    mouse.x < pause_g->button2->pos.x + pause_g->button2->rect.width &&
    mouse.y > pause_g->button2->pos.y &&
    mouse.y < pause_g->button2->pos.y + pause_g->button2->rect.height) {
        if (pause_g->button == 1) {
            sfSound_stop(pause_g->sound->sound);
            sfSound_play(pause_g->sound->sound);
            pause_g->outline->pos = pause_g->button2->pos;
            pause_g->button = 2;
        }
    }
}
