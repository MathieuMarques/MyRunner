/*
** EPITECH PROJECT, 2022
** create_text.c
** File description:
** create_text
*/

#include "my_runner.h"

text_score_t *create_plr_text(void)
{
    text_score_t *score = malloc(sizeof(text_score_t));
    sfFont *font = sfFont_createFromFile("font/8-bit fortress.ttf");
    sfText *text = sfText_create();
    sfText *text_score = sfText_create();
    sfText_setString(text, "SCORE");
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, 20);
    sfText_setString(text_score, "0");
    sfText_setFont(text_score, font);
    sfText_setCharacterSize(text_score, 20);
    sfText_setPosition(text, create_vectorf(20, 20));
    sfText_setPosition(text_score, create_vectorf(130, 20));
    sfText_setColor(text_score, create_color(216, 200, 151, 255));
    sfText_setColor(text, create_color(216, 200, 151, 255));
    score->font = font;
    score->text = text;
    score->text_score = text_score;
    score->score = 0;
    create_plr_text2(score);
    return score;
}

void create_plr_text2(text_score_t *score)
{
    sfText *life = sfText_create();
    sfText *life_nb = sfText_create();
    sfText_setString(life, "LIFE");
    sfText_setFont(life, score->font);
    sfText_setCharacterSize(life, 20);
    sfText_setString(life_nb, "2");
    sfText_setFont(life_nb, score->font);
    sfText_setCharacterSize(life_nb, 20);
    sfText_setPosition(life, create_vectorf(20, 60));
    sfText_setPosition(life_nb, create_vectorf(130, 60));
    sfText_setColor(life_nb, create_color(216, 200, 151, 255));
    sfText_setColor(life, create_color(216, 200, 151, 255));
    score->life = life;
    score->life_nb = life_nb;
}