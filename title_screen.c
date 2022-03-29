/*
** EPITECH PROJECT, 2021
** title_screen.c
** File description:
** title_screen
*/

#include "my_runner.h"

title_obj_t *create_title_obj(char *file, sfVector2f pos, sfIntRect rect)
{
    title_obj_t *obj = malloc(sizeof(title_obj_t));
    sfTexture *texture = sfTexture_createFromFile(file, NULL);
    sfSprite *sprite = sfSprite_create();
    if (sprite == NULL || texture == NULL)
        return NULL;
    obj->texture = texture;
    obj->sprite = sprite;
    obj->pos = pos;
    obj->rect = rect;
    return obj;
}

title_screen_t *create_title(char *file)
{
    title_screen_t *title = malloc(sizeof(title_screen_t));
    title->file = file;
    title->button = 1;
    title->bg = create_title_obj("sprites/screens/title_screen.png",
    create_vectorf(0, 0), create_rect(0, 0, 1280, 720));
    title->button1 =
    create_title_obj("sprites/buttons/play.png",
    create_vectorf(440, 200), create_rect(0, 0, 400, 100));
    title->button2 =
    create_title_obj("sprites/buttons/quit.png",
    create_vectorf(440, 400), create_rect(0, 0, 400, 100));
    title->outline =
    create_title_obj("sprites/buttons/outline.png",
    create_vectorf(440, 200), create_rect(0, 0, 400, 100));
    title->sound = create_sound("sounds/effects/menu.wav");
    title->music = sfMusic_createFromFile("sounds/music/title.ogg");
    sfMusic_setLoop(title->music, sfTrue);
    sfMusic_setVolume(title->music, 20);
    sfMusic_play(title->music);
    return title;
}

void title_screen(sfRenderWindow *window, sfEvent event, char *file)
{
    title_screen_t *title = create_title(file);
    while (sfRenderWindow_isOpen(window)) {
        if (title_events(window, event, title) == 0) {
            sfRenderWindow_clear(window, sfBlack);
            apply_title(window, title);
            sfRenderWindow_display(window);
        }
    }
}

void apply_title(sfRenderWindow *window, title_screen_t *title)
{
    sfSprite_setTexture(title->bg->sprite, title->bg->texture, 0);
    sfSprite_setTextureRect(title->bg->sprite, title->bg->rect);
    sfSprite_setPosition(title->bg->sprite, title->bg->pos);
    sfRenderWindow_drawSprite(window, title->bg->sprite, NULL);
    sfSprite_setTexture(title->button1->sprite, title->button1->texture, 0);
    sfSprite_setTextureRect(title->button1->sprite, title->button1->rect);
    sfSprite_setPosition(title->button1->sprite, title->button1->pos);
    sfRenderWindow_drawSprite(window, title->button1->sprite, NULL);
    sfSprite_setTexture(title->button2->sprite, title->button2->texture, 0);
    sfSprite_setTextureRect(title->button2->sprite, title->button2->rect);
    sfSprite_setPosition(title->button2->sprite, title->button2->pos);
    sfRenderWindow_drawSprite(window, title->button2->sprite, NULL);
    sfSprite_setTexture(title->outline->sprite, title->outline->texture, 0);
    sfSprite_setTextureRect(title->outline->sprite, title->outline->rect);
    sfSprite_setPosition(title->outline->sprite, title->outline->pos);
    sfRenderWindow_drawSprite(window, title->outline->sprite, NULL);
}

int title_events
(sfRenderWindow *window, sfEvent event, title_screen_t *title)
{
    int ret = 0;
    while (sfRenderWindow_pollEvent(window, &event)) {
        ret += close_window_title(window, event, title);
        ret += check_mouse_title(window, event, title);
        ret += check_input_screen(window, event, title);
    }
    return ret;
}
