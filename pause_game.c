/*
** EPITECH PROJECT, 2022
** pause_game.c
** File description:
** pause_game
*/

#include "my_runner.h"

void pause_game(sfRenderWindow *window, sfEvent event, all_game_obj_t *all)
{
    float last_time = 0.0;
    pause_game_t *pause_g = create_pause();
    while (sfRenderWindow_isOpen(window) &&
    event_pause(window, event, all->player, pause_g) == 0) {
        if (get_time_sec(all->clock) - last_time > 1 / FPS) {
            apply_to_window(window, all->player, all->bg, all->obj);
            apply_pause_obj(window, pause_g);
            sfRenderWindow_display(window);
            last_time = get_time_sec(all->clock);
        }
    }
    destroy_pause(pause_g);
}

pause_game_t *create_pause(void)
{
    pause_game_t *pause_g = malloc(sizeof(pause_game_t));
    pause_g->button = 1;
    pause_g->bg = create_title_obj("sprites/screens/mask.png",
    create_vectorf(0, 0), create_rect(0, 0, 1280, 720));
    pause_g->button1 =
    create_title_obj("sprites/buttons/resume.png",
    create_vectorf(440, 200), create_rect(0, 0, 400, 100));
    pause_g->button2 =
    create_title_obj("sprites/buttons/quit.png",
    create_vectorf(440, 400), create_rect(0, 0, 400, 100));
    pause_g->outline =
    create_title_obj("sprites/buttons/outline.png",
    create_vectorf(440, 200), create_rect(0, 0, 400, 100));
    pause_g->sound = create_sound("sounds/effects/menu.wav");
    return pause_g;
}

int event_pause
(sfRenderWindow *window, sfEvent event,
player_t *player, pause_game_t *pause_g)
{
    int ret = 0;
    while (sfRenderWindow_pollEvent(window, &event)) {
        close_window(window, event);
        check_move(event, player);
        ret += check_mouse_pause(window, event, pause_g);
        ret += check_input_pause(window, event, pause_g);
    }
    return ret;
}

wait_game_t *create_wait(void)
{
    wait_game_t *wait_game = malloc(sizeof(wait_game_t));
    wait_game->one =
    create_title_obj("sprites/screens/cd_1.png",
    create_vectorf(560, 10), create_rect(0, 0, 160, 160));
    wait_game->two =
    create_title_obj("sprites/screens/cd_2.png",
    create_vectorf(560, 10), create_rect(0, 0, 160, 160));
    wait_game->three =
    create_title_obj("sprites/screens/cd_3.png",
    create_vectorf(560, 10), create_rect(0, 0, 160, 160));
    return wait_game;
}

void wait_game(sfRenderWindow *window, sfEvent event, all_game_obj_t *all)
{
    wait_game_t *wait_game = create_wait();
    sfClock *clock = sfClock_create();
    float last_time = 0.0;
    int end = 0;
    while (sfRenderWindow_isOpen(window) && end == 0) {
        while (sfRenderWindow_pollEvent(window, &event)) {
            close_window(window, event);
            check_move(event, all->player);
        }
        if (get_time_sec(all->clock) - last_time > 1 / FPS) {
            apply_to_window(window, all->player, all->bg, all->obj);
            apply_cd(window, wait_game, clock);
            sfRenderWindow_display(window);
            last_time = get_time_sec(all->clock);
        }
        if (get_time_sec(clock) > 3)
            end = 1;
    }
    sfClock_destroy(clock);
}
