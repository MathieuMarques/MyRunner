/*
** EPITECH PROJECT, 2021
** title_screen2.c
** File description:
** title_screen2
*/

#include "my_runner.h"

int check_mouse_title
(sfRenderWindow *window, sfEvent event, title_screen_t *title)
{
    update_pose_mouse_ts(window, event, title);
    if (event.type == sfEvtMouseButtonPressed) {
        if (event.key.code == sfMouseLeft)
            return check_pos_mouse(window, event, title);
    }
    return 0;
}

int check_pos_mouse
(sfRenderWindow* window, sfEvent event, title_screen_t *title)
{
    if (event.mouseButton.x > title->button1->pos.x &&
    event.mouseButton.x < title->button1->pos.x + title->button1->rect.width &&
    event.mouseButton.y > title->button1->pos.y &&
    event.mouseButton.y < title->button1->pos.y +
    title->button1->rect.height) {
        char *file = title->file;
        destroy_title(title);
        runner(window, event, file);
        return 1;
    }
    if (event.mouseButton.x > title->button2->pos.x &&
    event.mouseButton.x < title->button2->pos.x + title->button2->rect.width &&
    event.mouseButton.y > title->button2->pos.y &&
    event.mouseButton.y < title->button2->pos.y +
    title->button2->rect.height) {
        destroy_title(title);
        sfRenderWindow_close(window);
        return 1;
    }
    return 0;
}

int close_window_title
(sfRenderWindow *window, sfEvent event, title_screen_t *title)
{
    if (event.type == sfEvtClosed) {
        destroy_title(title);
        sfRenderWindow_close(window);
        return 1;
    }
    return 0;
}

void destroy_title(title_screen_t *title)
{
    sfMusic_stop(title->music);
    sfMusic_destroy(title->music);
    destroy_title_obj(title->bg);
    destroy_title_obj(title->button1);
    destroy_title_obj(title->button2);
    destroy_title_obj(title->outline);
    sfSoundBuffer_destroy(title->sound->buffer);
    sfSound_destroy(title->sound->sound);
    free(title);
}

void destroy_title_obj(title_obj_t *obj)
{
    sfTexture_destroy(obj->texture);
    sfSprite_destroy(obj->sprite);
    free(obj);
}
