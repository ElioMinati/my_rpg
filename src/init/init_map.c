/*
** EPITECH PROJECT, 2022
** init_map.c
** File description:
** functions used to initialize map
*/

#include "rpg.h"

void init_gas(game_t *game)
{
    game->backgrounds[9].texture = sfTexture_createFromFile(
    "files/background/gas.png", NULL);
    game->backgrounds[9].sprite = get_sprite(game->backgrounds[9].texture);
    sfSprite_setPosition(game->backgrounds[9].sprite,
    get_position(-800, -1700));
    sfSprite_setScale(game->backgrounds[9].sprite, get_position(0.5, 0.5));
    game->backgrounds[9].pos = get_position(-800, -1700);
    init_more_backgrounds(game);
}

void init_map(game_t *game)
{
    game->backgrounds[3].texture = sfTexture_createFromFile(
    "files/background/map.png", NULL);
    game->backgrounds[3].sprite = get_sprite(game->backgrounds[3].texture);
    sfSprite_setPosition(game->backgrounds[3].sprite,
    get_position(-800, -1700));
    sfSprite_setScale(game->backgrounds[3].sprite, get_position(0.5, 0.5));
    game->backgrounds[3].pos = get_position(-800, -1700);
    game->backgrounds[4].texture = sfTexture_createFromFile(
    "files/background/garage.png", NULL);
    game->backgrounds[4].sprite = get_sprite(game->backgrounds[4].texture);
    sfSprite_setPosition(game->backgrounds[4].sprite, get_position(-50, 0));
    sfSprite_setScale(game->backgrounds[4].sprite, get_position(1.5, 1.5));
    game->backgrounds[5].texture = sfTexture_createFromFile(
    "files/background/dealership.png", NULL);
    game->backgrounds[5].sprite = get_sprite(game->backgrounds[5].texture);
    sfSprite_setPosition(game->backgrounds[5].sprite, get_position(0, 0));
    sfSprite_setScale(game->backgrounds[5].sprite, get_position(1.43, 1.43));
    init_parts_shop(game);
    game->race.stutu.has_played = 0;
    init_gas(game);
}

void init_more_backgrounds(game_t *game)
{
    game->backgrounds[12].texture = sfTexture_createFromFile(
    "files/background/countryside.png", NULL);
    game->backgrounds[12].sprite = get_sprite(game->backgrounds[12].texture);
    sfSprite_setPosition(game->backgrounds[12].sprite, get_position(0, 0));
    sfSprite_setScale(game->backgrounds[12].sprite, get_position(1, 1));
    game->backgrounds[13].texture = sfTexture_createFromFile(
    "files/background/night.png", NULL);
    game->backgrounds[13].sprite = get_sprite(game->backgrounds[13].texture);
    sfSprite_setPosition(game->backgrounds[13].sprite, get_position(0, 0));
    sfSprite_setScale(game->backgrounds[13].sprite, get_position(1, 1));
}
