/*
** EPITECH PROJECT, 2021
** open_map.c
** File description:
** open_map
*/

#include "my.h"
#include <fcntl.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int count_game_objects(char *map)
{
    int count = 0;
    for (int i = 0; map[i] != '\0'; i++) {
        if (map[i] != '\n' && map[i] != '\0' && map[i] != ' ')
            count++;
    }
    return count;
}

int open_file(char const *filepath)
{
    int fd = open(filepath, O_RDONLY);
    return fd;
}

int get_size(char const *filepath)
{
    char *buf = NULL;
    int size = 0;
    size_t buf_size = 0;
    ssize_t line_size = 0;
    FILE *fp = fopen(filepath, "r");
    while (line_size >= 0) {
        line_size = getline(&buf, &buf_size, fp);
        size += line_size;
    }
    size += 2;
    free(buf);
    fclose(fp);
    return size;
}

char *load_file(char const *filepath)
{
    int output = 0;
    char *buffer = NULL;
    int size = get_size(filepath);
    int fd = open_file(filepath);
    if (fd == -1)
        return NULL;
    buffer = malloc(size * sizeof(char));
    output = read(fd, buffer, size);
    if (output == -1)
        return NULL;
    buffer[size - 1] = '\0';
    close(fd);
    return buffer;
}
