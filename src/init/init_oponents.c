/*
** EPITECH PROJECT, 2022
** init_oponents.c
** File description:
** functions used to initialize oponents
*/

#include "rpg.h"

void init_all_cars(game_t *game)
{
    create_205(game->cars, 0);
    create_206(game->cars, 1);
    create_civic(game->cars, 2);
    create_cooper(game->cars, 3);
    create_crx(game->cars, 4);
    create_golf(game->cars, 5);
    create_mojang(game->cars, 6);
    create_850r(game->cars, 7);
    create_camaro_ss(game->cars, 8);
    create_e36(game->cars, 9);
    create_cobalt(game->cars, 10);
    create_180sx(game->cars, 11);
    create_z76(game->cars, 12);
    create_is200(game->cars, 13);
    create_e92(game->cars, 14);
    create_350z(game->cars, 15);
    create_bel_air(game->cars, 16);
    create_rx7(game->cars, 17);
    create_silvia(game->cars, 18);
    create_supra(game->cars, 19);
}
