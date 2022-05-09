/*
** EPITECH PROJECT, 2022
** my_RPG
** File description:
** destroyer
*/

#include "rpg.h"

void destroyer(sfRenderWindow *window, game_t *game)
{
    sfRenderWindow_destroy(window);
    if (game->race.stutu.has_played == 1)
        sfMusic_destroy(game->race.stutu.music);
    if (game->music.music != NULL)
        sfMusic_destroy(game->music.music);
    if (game->scene == 5)
        sfMusic_destroy(game->race.music.music);
}
