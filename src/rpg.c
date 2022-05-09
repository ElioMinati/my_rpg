/*
** EPITECH PROJECT, 2022
** my_RPG
** File description:
** rpg
*/

#include <time.h>
#include "rpg.h"

void my_rpg(sfRenderWindow *window, game_t *game)
{
    srand(time(NULL));
    rpg_init(game);
    game->win = window;
    music_menu(game);
    sfRenderWindow_setFramerateLimit(window, 60u);
    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &game->event))
            inputhandler(window, game);
        if (game->scene == 2) colision(game, window);
        music(window, game);
        analyse_events(window, game);
        choose(window, game);
    }
    destroyer(window, game);
}