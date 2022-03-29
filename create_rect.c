/*
** EPITECH PROJECT, 2021
** create_rect.c
** File description:
** create_rect
*/

#include "my_runner.h"

sfIntRect create_rect(int top, int left, int width, int height)
{
    sfIntRect rect;
    rect.top = top;
    rect.left = left;
    rect.width = width;
    rect.height = height;
    return rect;
}
