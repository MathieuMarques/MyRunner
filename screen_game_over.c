/*
** EPITECH PROJECT, 2022
** screen_game_over.c
** File description:
** screen_game_over
*/

#include "my_runner.h"

void screen_game_over
(sfRenderWindow *window, sfEvent event, all_game_obj_t *all)
{
    screen_game_over_t *g_o;
    sfMusic_stop(all->music);
    if (all->player->win == 1)
        g_o = create_win(all->player);
    else
        g_o = create_game_over(all->player);
    while (sfRenderWindow_isOpen(window)) {
        if (game_over_event(window, event, g_o, all) == 0) {
            sfRenderWindow_clear(window, sfBlack);
            apply_game_over(window, all->player, g_o);
            sfRenderWindow_display(window);
        }
    }
}

screen_game_over_t *create_game_over(player_t *player)
{
    screen_game_over_t *g_o = malloc(sizeof(screen_game_over_t));
    char *char_score = int_to_char(player->score->score);
    g_o->button = 1;
    g_o->bg = create_title_obj("sprites/screens/game_over.png",
    create_vectorf(0, 0), create_rect(0, 0, 1280, 720));
    g_o->button1 =
    create_title_obj("sprites/buttons/restart.png",
    create_vectorf(440, 350), create_rect(0, 0, 400, 100));
    g_o->button2 = create_title_obj("sprites/buttons/quit.png",
    create_vectorf(440, 500), create_rect(0, 0, 400, 100));
    g_o->outline = create_title_obj("sprites/buttons/outline.png",
    create_vectorf(440, 350), create_rect(0, 0, 400, 100));
    sfText_setString(player->score->text_score, char_score);
    sfText_setPosition(player->score->text_score, create_vectorf(750, 230));
    sfText_setCharacterSize(player->score->text_score, 40);
    sfText_setColor(player->score->text_score, create_color(122, 27, 27, 255));
    free(char_score);
    create_game_over2(player, g_o);
    return g_o;
}

void create_game_over2(player_t *player, screen_game_over_t *g_o)
{
    sfText_setString(player->score->text, "FINAL SCORE");
    sfText_setPosition(player->score->text, create_vectorf(280, 230));
    sfText_setCharacterSize(player->score->text, 40);
    sfText_setColor(player->score->text, create_color(122, 27, 27, 255));
    g_o->sound = create_sound("sounds/effects/menu.wav");
    g_o->music = sfMusic_createFromFile("sounds/music/lose.ogg");
    sfMusic_setLoop(g_o->music, sfTrue);
    sfMusic_setVolume(g_o->music, 30);
    sfMusic_play(g_o->music);
}

screen_game_over_t *create_win(player_t *player)
{
    screen_game_over_t *g_o = malloc(sizeof(screen_game_over_t));
    player->score->score += 1000 * player->life;
    char *char_score = int_to_char(player->score->score);
    g_o->button = 1;
    g_o->bg = create_title_obj("sprites/screens/win.png",
    create_vectorf(0, 0), create_rect(0, 0, 1280, 720));
    g_o->button1 =
    create_title_obj("sprites/buttons/restart.png",
    create_vectorf(440, 350), create_rect(0, 0, 400, 100));
    g_o->button2 = create_title_obj("sprites/buttons/quit.png",
    create_vectorf(440, 500), create_rect(0, 0, 400, 100));
    g_o->outline = create_title_obj("sprites/buttons/outline.png",
    create_vectorf(440, 350), create_rect(0, 0, 400, 100));
    sfText_setString(player->score->text_score, char_score);
    sfText_setPosition(player->score->text_score, create_vectorf(750, 230));
    sfText_setCharacterSize(player->score->text_score, 40);
    sfText_setColor(player->score->text_score, create_color(216, 200, 151, 255));
    free(char_score);
    create_win2(player, g_o);
    return g_o;
}

void create_win2(player_t *player, screen_game_over_t *g_o)
{
    sfText_setString(player->score->text, "FINAL SCORE");
    sfText_setPosition(player->score->text, create_vectorf(280, 230));
    sfText_setCharacterSize(player->score->text, 40);
    sfText_setColor(player->score->text, create_color(216, 200, 151, 255));
    g_o->sound = create_sound("sounds/effects/menu.wav");
    g_o->music = sfMusic_createFromFile("sounds/music/win.ogg");
    sfMusic_setLoop(g_o->music, sfTrue);
    sfMusic_setVolume(g_o->music, 25);
    sfMusic_play(g_o->music);
}
