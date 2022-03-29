/*
** EPITECH PROJECT, 2021
** create_color.c
** File description:
** create_color
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <stdlib.h>
#include "my_runner.h"

sfColor create_color(int red, int green, int blue, int alpha)
{
    sfColor color;
    color.r = red;
    color.g = green;
    color.b = blue;
    color.a = alpha;
    return color;
}
