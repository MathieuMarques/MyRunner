/*
** EPITECH PROJECT, 2021
** my_runner.h
** File description:
** my_runner
*/

#include <unistd.h>
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/System/Export.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#ifndef MY_RUNNER_H_
    #define MY_RUNNER_H_

static const char *NAME = "RUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUNNNNNNNNNNNNN";
static const float FPS = 60.0;
static const int WIDTH = 1280;
static const int HEIGHT = 720;

static const float MOVE_SPEED = 2.5;
static const int JUMP_HEIGHT = 27;

static const int TILE_SIZE = 40;

enum type_e {
    block,
    spike,
    end,
    enemy,
    null
};

enum anim_e {
    anim_run,
    anim_run_tr,
    anim_jump,
    anim_jump_tr,
    fall,
    fall_tr
};

typedef struct sound_s {
    sfSoundBuffer *buffer;
    sfSound *sound;
} sound_t;

typedef struct plr_anim_s {
    sfTexture *run;
    sfTexture *jump;
    sfTexture *run_t;
    sfTexture *jump_t;
} plr_anim_t;

typedef struct move_s {
    sfBool right;
    sfBool left;
    sfBool jump;
} move_t;

typedef struct text_score_s {
    int score;
    sfFont *font;
    sfText *text;
    sfText *text_score;
    sfText *life;
    sfText *life_nb;
} text_score_t;

typedef struct player_s {
    sfSprite *sprite;
    sfTexture *texture;
    plr_anim_t *plr_anim;
    sfVector2f pos;
    sfIntRect rect;
    sfIntRect hitbox;
    sfVector2f vel;
    move_t move;
    sfBool is_jumping;
    enum anim_e anim;
    float last_time;
    float last_time_an;
    sfBool game_over;
    text_score_t *score;
    int life;
    int invisibility;
    int win;
    sfTime offset;
    sfSoundBuffer *buffer;
    sfSound *sound;
} player_t;

typedef struct game_bg_s {
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f pos;
    sfIntRect rect;
    float speed;
    sfIntRect hitbox;
} game_bg_t;

typedef struct game_object_s {
    enum type_e type;
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f pos;
    sfIntRect rect;
    float speed;
    sfVector2f vel;
    float last_time;
    int id;
} game_object_t;

typedef struct create_map_s {
    int x;
    int y;
    int index;
    int count;
} create_map_t;

typedef struct title_obj_s {
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f pos;
    sfIntRect rect;
} title_obj_t;

typedef struct screen_game_over_s {
    int button;
    title_obj_t *bg;
    title_obj_t *button1;
    title_obj_t *button2;
    title_obj_t *outline;
    sound_t *sound;
    sfMusic *music;
} screen_game_over_t;

typedef struct pause_game_s {
    int button;
    title_obj_t *bg;
    title_obj_t *button1;
    title_obj_t *button2;
    title_obj_t *outline;
    sound_t *sound;
} pause_game_t;

typedef struct wait_game_s {
    title_obj_t *one;
    title_obj_t *two;
    title_obj_t *three;
} wait_game_t;

typedef struct title_screen_s {
    char *file;
    int button;
    title_obj_t *bg;
    title_obj_t *button1;
    title_obj_t *button2;
    title_obj_t *outline;
    sound_t *sound;
    sfMusic *music;
} title_screen_t;

typedef struct all_game_obj_s {
    char *file;
    player_t *player;
    game_object_t **obj;
    game_bg_t **bg;
    sfMusic *music;
    sfClock *clock;
} all_game_obj_t;

void print_help(void);
int flag_handler(char *arg);

void events(sfRenderWindow *window, sfEvent event, all_game_obj_t *all);
int create_window(char *file);
void runner(sfRenderWindow *window, sfEvent event, char *file);
void close_window(sfRenderWindow *window, sfEvent event);
void move_rect(sfIntRect *rect, int offset, int max_value);
void apply_to_window
(sfRenderWindow *window, player_t *player, game_bg_t **bg,
game_object_t **obj);
float get_time_sec(sfClock *clock);
void destroy_all_obj
(player_t *player, game_bg_t **bg, game_object_t **obj, sfClock *clock);
char *int_to_char(int nb);
void check_pause(sfRenderWindow *window, sfEvent event, all_game_obj_t *all);
void update_all
(player_t *player, game_object_t **obj, game_bg_t **bg, sfClock *clock);
sfMusic *create_music_game(void);
all_game_obj_t *create_all_obj(char *file);

sfIntRect create_rect(int top, int left, int width, int height);
sfVector2f create_vectorf(float x, float y);
sfColor create_color(int red, int green, int blue, int alpha);

player_t *create_player(void);
void destroy_player(player_t *player);
void update_sprite(player_t *player, sfClock *clock);
void collide_x(player_t *player, game_object_t **obj);
void collide_x_2(player_t *player, game_object_t **obj, int i);
void collide_x_3(player_t *player, game_object_t **obj, int i);
void collide_y(player_t *player, game_object_t **obj);
void collide_y_2(player_t *player, game_object_t **obj, int i);
void collide_y_3(player_t *player, game_object_t **obj, int i);
int is_colliding(player_t *player, game_object_t *obj);
void gravity(player_t *player, game_object_t **obj);
void update_pos(player_t *player, game_object_t **obj, sfClock *clock);
void jump(player_t *player, game_object_t **obj);
void check_move(sfEvent event, player_t *player);
void move(player_t *player, game_object_t **obj);
void update_player_anim
(player_t *player, game_object_t **obj, sfClock *clock);
int is_on_ground(player_t *player, game_object_t **obj);
int is_on_ground_2(player_t *player, game_object_t **obj, int i);
void player_anim(player_t *player, sfClock *clock);
void create_player2(player_t *player);
void create_player3(player_t *player);
void update_player(player_t *player, game_object_t **obj, sfClock *clock);
int is_game_over(player_t *player, game_object_t **obj);
int is_game_over2(player_t *player, game_object_t **obj, int i);
text_score_t *create_plr_text(void);
void create_plr_text2(text_score_t *score);
void display_score(sfRenderWindow *window, player_t *player);
void change_sprite(player_t *player);
void change_sprite2(player_t *player);
void change_sprite3(player_t *player);
void update_score(player_t *player, sfClock *clock);

game_bg_t *create_bg
(float speed, char *path, sfIntRect rect, sfIntRect hitbox);
void destroy_object(game_bg_t *obj);
game_bg_t **create_all_layer(void);
void update_all_bg(game_bg_t **bg, sfClock *clock);
void apply_bg(sfRenderWindow *window, game_bg_t *bg);
void update_bg(game_bg_t *bg, sfClock *clock);
void destroy_background(game_bg_t **bg);
void create_all_layer2(game_bg_t **bg);

game_object_t **create_tile_map(char *file);
game_object_t *create_game_object
(enum type_e type, sfVector2f pos, char *file);
int open_file(char const *filepath);
char *load_file(char const *filepath);
int get_size(char const *filepath);
void destroy_object2(game_object_t **obj);
void apply_obj(sfRenderWindow *window, game_object_t *obj);
create_map_t create_map_struct(void);
int is_in_screen(game_object_t *obj);
void move_tile(game_object_t **obj);
void place_tile(game_object_t **obj, create_map_t *map_id, char *map);
int count_game_objects(char *map);
game_object_t *create_end
(enum type_e type, sfVector2f pos, char *file);
void place_tile2(game_object_t **obj, create_map_t *map_id, char *map);
game_object_t *create_enemy_obj
(enum type_e type, sfVector2f pos, char *file, int id);
void create_enemys(game_object_t **obj);

void title_screen(sfRenderWindow *window, sfEvent event, char *file);
title_screen_t *create_title(char *file);
title_obj_t *create_title_obj(char *file, sfVector2f pos, sfIntRect rect);
void apply_title(sfRenderWindow *window, title_screen_t *title);
int title_events
(sfRenderWindow *window, sfEvent event, title_screen_t *title);
int check_mouse_title
(sfRenderWindow *window, sfEvent event, title_screen_t *title);
int check_pos_mouse
(sfRenderWindow* window, sfEvent event, title_screen_t *title);
void destroy_title(title_screen_t *title);
void destroy_title_obj(title_obj_t *obj);
int close_window_title
(sfRenderWindow *window, sfEvent event, title_screen_t *title);
int check_input_screen
(sfRenderWindow *window, sfEvent event, title_screen_t *title);
void move_outline
(sfRenderWindow *window, sfEvent event, title_screen_t *title, int move);
void check_pos_outline
(sfRenderWindow *window, sfEvent event, title_screen_t *title);
sound_t *create_sound(char *file);
void update_pose_mouse_ts
(sfRenderWindow *window, sfEvent event, title_screen_t *title);

void screen_game_over
(sfRenderWindow *window, sfEvent event, all_game_obj_t *all);
screen_game_over_t *create_game_over(player_t *player);
void create_game_over2(player_t *player, screen_game_over_t *g_o);
int game_over_event
(sfRenderWindow *window, sfEvent event,
screen_game_over_t *g_o, all_game_obj_t *all);
int close_window_g_o
(sfRenderWindow *window, sfEvent event,
screen_game_over_t *g_o, all_game_obj_t *all);
void destroy_g_o(screen_game_over_t *g_o);
void apply_game_over
(sfRenderWindow *window, player_t *player, screen_game_over_t *g_o);
int check_input_g_o
(sfRenderWindow *window, sfEvent event,
screen_game_over_t *g_o, all_game_obj_t *all);
int check_mouse_g_o
(sfRenderWindow *window, sfEvent event,
screen_game_over_t *g_o, all_game_obj_t *all);
int check_pos_mouse_g_o
(sfRenderWindow* window, sfEvent event,
screen_game_over_t *g_o, all_game_obj_t *all);
int check_pos_mouse_g_o2
(sfRenderWindow *window, sfEvent event,
screen_game_over_t *g_o, all_game_obj_t *all);
void check_pos_outline_g_o
(sfRenderWindow *window, sfEvent event,
screen_game_over_t *g_o, all_game_obj_t *all);
void move_outline_g_o(screen_game_over_t *g_o, int move);
void update_pose_mouse_g_o
(sfRenderWindow *window, sfEvent event, screen_game_over_t *g_o);
void update_pose_mouse_g_o1
(sfRenderWindow *window, sfEvent event, screen_game_over_t *g_o);
void update_pose_mouse_g_o2
(sfRenderWindow *window, sfEvent event, screen_game_over_t *g_o);
screen_game_over_t *create_win(player_t *player);
void create_win2(player_t *player, screen_game_over_t *g_o);

void pause_game(sfRenderWindow *window, sfEvent event, all_game_obj_t *all);
int event_pause
(sfRenderWindow *window, sfEvent event,
player_t *player, pause_game_t *pause_g);
int event_continue(sfRenderWindow *window, sfEvent event);
void wait_game(sfRenderWindow *window, sfEvent event, all_game_obj_t *all);
pause_game_t *create_pause(void);
void apply_pause_obj(sfRenderWindow *window, pause_game_t *pause_g);
void destroy_pause(pause_game_t *pause_g);
int check_mouse_pause
(sfRenderWindow *window, sfEvent event, pause_game_t *pause_g);
void update_pose_mouse_pa1
(sfRenderWindow *window, sfEvent event, pause_game_t *pause_g);
void update_pose_mouse_pa2
(sfRenderWindow *window, sfEvent event, pause_game_t *pause_g);
int check_pos_mouse_pa
(sfRenderWindow* window, sfEvent event, pause_game_t *p);
int check_input_pause
(sfRenderWindow *window, sfEvent event, pause_game_t *pause_g);
void move_outline_pause
(sfRenderWindow *window, sfEvent event, pause_game_t *pause_g, int move);
void check_pos_outline_pa
(sfRenderWindow *window, sfEvent event, pause_game_t *pause_g);
void apply_cd(sfRenderWindow *window, wait_game_t *wait_game, sfClock *clock);
void apply_cd2
(sfRenderWindow *window, wait_game_t *wait_game, sfClock *clock);
wait_game_t *create_wait(void);

void update_enemy(game_object_t **obj, sfClock *clock);
void spawn_enemy(game_object_t **obj);
void enemy_collide_x(game_object_t *obj, game_object_t **all_obj);
void enemy_collide_y(game_object_t *obj, game_object_t **all_obj);
int is_enemy_colliding(game_object_t *obj, game_object_t *obj2);
void physics_enemy(game_object_t *obj, game_object_t **all_obj);

#endif /* !MY_RUNNER_H_ */
