/*
** EPITECH PROJECT, 2021
** create_vector.c
** File description:
** create_vector
*/

#include "my_runner.h"

sfVector2f create_vectorf(float x, float y)
{
    sfVector2f vector;
    vector.x = x;
    vector.y = y;
    return vector;
}
