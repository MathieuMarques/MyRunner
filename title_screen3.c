/*
** EPITECH PROJECT, 2021
** title_screen3.c
** File description:
** title_screen3
*/

#include "my_runner.h"

int check_input_screen
(sfRenderWindow *window, sfEvent event, title_screen_t *title)
{
    if (event.type == sfEvtKeyPressed) {
        if (event.key.code == sfKeyEnter) {
            check_pos_outline(window, event, title);
            return 1;
        }
        if (event.key.code == sfKeyUp) {
            move_outline(window, event, title, -1);
        }
        if (event.key.code == sfKeyDown) {
            move_outline(window, event, title, 1);
        }
    }
    return 0;
}

void move_outline
(sfRenderWindow *window, sfEvent event, title_screen_t *title, int move)
{
    sfSound_stop(title->sound->sound);
    sfSound_play(title->sound->sound);
    title->button += move;
    if (title->button > 2)
        title->button = 1;
    if (title->button < 1)
        title->button = 2;
    if (title->button == 1)
        title->outline->pos = title->button1->pos;
    if (title->button == 2)
        title->outline->pos = title->button2->pos;
}

void check_pos_outline
(sfRenderWindow *window, sfEvent event, title_screen_t *title)
{
    if (title->button == 1) {
        char *file = title->file;
        destroy_title(title);
        runner(window, event, file);
        return;
    }
    if (title->button == 2) {
        destroy_title(title);
        sfRenderWindow_close(window);
        return;
    }
}

sound_t *create_sound(char *file)
{
    sound_t *struct_sound = malloc(sizeof(sound_t));
    sfSoundBuffer *buffer = sfSoundBuffer_createFromFile(file);
    sfSound *sound = sfSound_create();
    sfSound_setBuffer(sound, buffer);
    struct_sound->buffer = buffer;
    struct_sound->sound = sound;
    return struct_sound;
}
