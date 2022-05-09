/*
** EPITECH PROJECT, 2022
** main
** File description:
** main
*/

#include "rpg.h"
#include "my.h"

int main(int argc, char **argv, char **env)
{
    game_t game;
    sfRenderWindow *window = create_renderwindow(1920, 1080, 32, "My_RPG");

    if (env[0] == NULL)
        return 84;
    if (argc == 2 && my_strcmp(argv[1], "-h") == 0) {
        display_help();
        return 0;
    }
    my_rpg(window, &game);
}
