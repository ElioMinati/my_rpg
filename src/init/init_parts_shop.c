/*
** EPITECH PROJECT, 2022
** init_parts_shop
** File description:
** initialize parts shop
*/

#include <stdlib.h>
#include "rpg.h"

static void init_air_filters(game_t *game)
{
    game->parts[5].texture = sfTexture_createFromFile(
    "files/car_parts/sport_air_filter.png", NULL);
    game->parts[5].sprite = get_sprite(game->parts[5].texture);
    sfSprite_setPosition(game->parts[5].sprite, get_position(1390, 460));
    sfSprite_setScale(game->parts[5].sprite, get_position(1.6, 1.6));
    game->parts[5].is_toggled = 0;
    game->parts[6].texture = sfTexture_createFromFile(
    "files/car_parts/sport_air_filter.png", NULL);
    game->parts[6].sprite = get_sprite(game->parts[6].texture);
    sfSprite_setOrigin(game->parts[6].sprite, get_position(35.5, 37.5));
    sfSprite_setPosition(game->parts[6].sprite, get_position(485, 838));
    sfSprite_setScale(game->parts[6].sprite, get_position(1.4, 1.4));
    game->parts[6].is_toggled = 0;
    game->parts[7].texture = sfTexture_createFromFile(
    "files/car_parts/really_sport_air_filter.png", NULL);
    game->parts[7].sprite = get_sprite(game->parts[7].texture);
    sfSprite_setOrigin(game->parts[7].sprite, get_position(35, 34));
    sfSprite_setPosition(game->parts[7].sprite, get_position(785, 834));
    sfSprite_setScale(game->parts[7].sprite, get_position(1.4, 1.4));
    game->parts[7].is_toggled = 0; init_more_air_filters(game);
}

static void init_turbo_parts(game_t *game)
{
    game->parts[2].texture = sfTexture_createFromFile(
    "files/car_parts/bi-turbo.png", NULL);
    game->parts[2].sprite = get_sprite(game->parts[2].texture);
    sfSprite_setOrigin(game->parts[2].sprite, get_position(46.5, 45.5));
    sfSprite_setPosition(game->parts[2].sprite, get_position(1096, 845));
    sfSprite_setScale(game->parts[2].sprite, get_position(1.2, 1.2));
    game->parts[2].is_toggled = 0;
    game->parts[3].texture = sfTexture_createFromFile(
    "files/car_parts/diamond_turbo.png", NULL);
    game->parts[3].sprite = get_sprite(game->parts[3].texture);
    sfSprite_setOrigin(game->parts[3].sprite, get_position(50.5, 50.5));
    sfSprite_setPosition(game->parts[3].sprite, get_position(1400, 850));
    sfSprite_setScale(game->parts[3].sprite, get_position(1.2, 1.2));
    game->parts[3].is_toggled = 0;
    game->parts[4].texture = sfTexture_createFromFile(
    "files/car_parts/turbo.png", NULL);
    game->parts[4].sprite = get_sprite(game->parts[4].texture);
    sfSprite_setPosition(game->parts[4].sprite, get_position(1640, 600));
    sfSprite_setScale(game->parts[4].sprite, get_position(1.2, 1.2));
    game->parts[4].is_toggled = 0; game->parts->selected = -1;
}

static void init_extra_parts(game_t *game)
{
    game->parts[1].texture = sfTexture_createFromFile(
    "files/car_parts/turbo.png", NULL);
    game->parts[1].sprite = get_sprite(game->parts[1].texture);
    sfSprite_setOrigin(game->parts[1].sprite, get_position(49.9, 49.5));
    sfSprite_setPosition(game->parts[1].sprite, get_position(800, 850));
    sfSprite_setScale(game->parts[1].sprite, get_position(1.2, 1.2));
    game->parts[1].is_toggled = 0;
    init_turbo_parts(game);
    init_air_filters(game);
}

void init_parts_shop(game_t *game)
{
    game->parts = malloc(25 * sizeof(button_t));
    game->parts->nb_buttons = 5;
    game->backgrounds[8].texture = sfTexture_createFromFile(
    "files/background/parts_shop.png", NULL);
    game->backgrounds[8].sprite = get_sprite(game->backgrounds[8].texture);
    sfSprite_setScale(game->backgrounds[8].sprite, get_position(1.45, 1.45));
    sfSprite_setPosition(game->backgrounds[8].sprite, get_position(-100, 0));
    game->parts[0].texture = sfTexture_createFromFile(
    "files/car_parts/small_turbo.png", NULL);
    game->parts[0].sprite = get_sprite(game->parts[0].texture);
    sfSprite_setOrigin(game->parts[0].sprite, get_position(37, 37));
    sfSprite_setPosition(game->parts[0].sprite, get_position(487, 837));
    sfSprite_setScale(game->parts[0].sprite, get_position(1.2, 1.2));
    game->parts[0].is_toggled = 0;
    init_extra_parts(game);
}
