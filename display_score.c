/*
** EPITECH PROJECT, 2022
** display_score.c
** File description:
** display_score
*/

#include "my_runner.h"
#include "my.h"

int find_power_itc(int nb)
{
    int i = 0;
    for (i = 0; nb > 0; i++)
        nb /= 10;
    return i;
}

char *int_to_char(int nb)
{
    int size = find_power_itc(nb);
    char *nbr = malloc(sizeof(char) * size + 1);
    int current = 0;
    int i = 0;
    for (i = 0; i < size; i++) {
        current = nb % 10;
        nbr[i] = current + '0';
        nb /= 10;
    }
    nbr[i] = '\0';
    my_revstr(nbr);
    return nbr;
}

void display_score(sfRenderWindow *window, player_t *player)
{
    char *char_score = int_to_char(player->score->score);
    char *life_nb = int_to_char(player->life);
    sfRenderWindow_drawText(window, player->score->text, NULL);
    sfText_setString(player->score->text_score, char_score);
    sfRenderWindow_drawText(window, player->score->text_score, NULL);
    sfRenderWindow_drawText(window, player->score->life, NULL);
    sfText_setString(player->score->life_nb, life_nb);
    sfRenderWindow_drawText(window, player->score->life_nb, NULL);
    free(char_score);
}
