/*
** EPITECH PROJECT, 2021
** window.c
** File description:
** window
*/

#include "my_runner.h"
#include "my.h"

int create_window(char *file)
{
    unsigned int width = WIDTH;
    unsigned int height = HEIGHT;
    sfVideoMode mode = {width, height, 32};
    sfEvent event;
    sfRenderWindow *window =
    sfRenderWindow_create(mode, NAME, sfResize | sfClose, NULL);
    sfRenderWindow_setFramerateLimit(window, FPS);

    title_screen(window, event, file);

    sfRenderWindow_destroy(window);
    return 0;
}

float get_time_sec(sfClock *clock)
{
    sfTime time;
    float seconds = 0.0;
    time = sfClock_getElapsedTime(clock);
    seconds = time.microseconds / 1000000.0;
    return seconds;
}

void runner(sfRenderWindow *window, sfEvent event, char *file)
{
    float last_time = 0.0;
    all_game_obj_t *all = create_all_obj(file);
    while (sfRenderWindow_isOpen(window) && all->player->game_over != sfTrue) {
        events(window, event, all);
        if (get_time_sec(all->clock) - last_time > 1 / FPS) {
            sfRenderWindow_clear(window, sfBlack);
            update_all(all->player, all->obj, all->bg, all->clock);
            apply_to_window(window, all->player, all->bg, all->obj);
            sfRenderWindow_display(window);
            last_time = get_time_sec(all->clock);
        }
    }
    if (all->player->game_over == sfTrue)
        screen_game_over(window, event, all);
    else {
        destroy_all_obj(all->player, all->bg, all->obj, all->clock);
        sfMusic_destroy(all->music);
        free(all);
    }
}

void update_sprite(player_t *player, sfClock *clock)
{
    float seconds = 0.0;
    sfTime time = sfClock_getElapsedTime(clock);
    seconds = time.microseconds / 1000000.0;
    if (seconds > 0.15) {
        move_rect(&player->rect, 30, 240);
        sfClock_restart(clock);
    }
}

void apply_to_window
(sfRenderWindow *window, player_t *player, game_bg_t **bg,
game_object_t **obj)
{
    for (int i = 9; i > 3; i--)
        apply_bg(window, bg[i]);
    apply_bg(window, bg[10]);
    sfSprite_setTexture(player->sprite, player->texture, 0);
    sfSprite_setTextureRect(player->sprite, player->rect);
    sfSprite_setPosition(player->sprite, player->pos);
    sfRenderWindow_drawSprite(window, player->sprite, NULL);
    for (int i = 3; i > 0; i--)
        apply_bg(window, bg[i]);
    for (int i = 0; obj[i]->type != null; i++) {
        apply_obj(window, obj[i]);
    }
    display_score(window, player);
}
