/*
** EPITECH PROJECT, 2022
** my_RPG
** File description:
** choose_time
*/

#include "rpg.h"

void choose_time(sfRenderWindow *win, game_t *game)
{
    if (game->time == 5)
        game->time = rand() % 4;
    if (game->time == 1)
        sfRenderWindow_drawSprite(win, game->parallax[1].sprite, NULL);
    if (game->time == 2)
        sfRenderWindow_drawSprite(win, game->backgrounds[12].sprite, NULL);
    if (game->time == 3)
        sfRenderWindow_drawSprite(win, game->backgrounds[13].sprite, NULL);
    if (game->time == 0)
        sfRenderWindow_drawSprite(win, game->backgrounds[11].sprite, NULL);
}
