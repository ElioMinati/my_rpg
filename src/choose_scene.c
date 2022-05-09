/*
** EPITECH PROJECT, 2022
** my_RPG
** File description:
** choose_scene
*/

#include "rpg.h"

void choose(sfRenderWindow *window, game_t *game)
{
    if (game->scene == 0) display_start(window, game);
    if (game->scene == 1) display_car_choice(window, game);
    if (game->scene == 2) display_game(window, game);
    if (game->scene == 3) display_garage(window, game);
    if (game->scene == 4) display_dealership(window, game);
    if (game->scene == 5) display_race(window, game);
    if (game->scene == 6) display_end(window, game);
    if (game->scene == 7) display_rules(window, game);
    if (game->scene == 8) display_part_shop(window, game);
    if (game->scene == 9) display_anim(window, game);
    if (game->scene == 10) display_end_anim(window, game);
}
