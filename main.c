/*
** EPITECH PROJECT, 2021
** main.c
** File description:
** main
*/

#include "my_runner.h"
#include "my.h"

int flag_handler(char *arg)
{
    int fd = 0;
    if (arg[0] == '-' && arg[1] == 'i' && arg[2] == '\0') {
        return 0;
    } else {
        fd = open_file(arg);
        if (fd == -1)
            return 84;
        close(fd);
        create_window(arg);
    }
}

void print_help(void)
{
    my_printf("Finite runner created with CSFML.\n\n");
    my_printf("USAGE\n");
    my_printf(" ./my_runner map.txt\n\n\n");
    my_printf("OPTIONS\n");
    my_printf(" -h               print the usage and quit.\n\n");
    my_printf("USER INTERACTIONS\n");
    my_printf(" LEFT_ARROW       move character to the left.\n");
    my_printf(" RIGHT_ARROW      move character to the right.\n");
    my_printf(" SPACE_KEY        jump.\n");
    my_printf(" ESCAPE           pause the game.\n");
    my_printf(" ENTER            select the button in menus ");
    my_printf("(you can also click on it).\n");
}

int main(int argc, char **argv)
{
    srand(time(0));
    if (argc == 2 && argv[1][0] == '-' && argv[1][1] == 'h' &&
    argv[1][2] == '\0') {
        print_help();
        return 0;
    }
    if (argc < 2) {
        write(2, "./my_runner: bad arguments: 0 given \
but 1 is required\nretry with -h\n", 69);
        return 84;
    }
    if (argc == 2) {
        return flag_handler(argv[1]);
    }
    return 84;
}
