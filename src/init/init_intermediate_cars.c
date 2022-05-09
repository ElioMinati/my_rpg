/*
** EPITECH PROJECT, 2022
** init_intermediate_cars
** File description:
** initialize intermediate cars
*/

#include "rpg.h"

void create_bel_air(car_t *cars, int index)
{
    cars[index].texture = sfTexture_createFromFile("files/cars/bel_air.png",
    NULL);
    cars[index].sprite = get_sprite(cars[index].texture);
    cars[index].offset = get_position(273, 120);
    sfSprite_setOrigin(cars[index].sprite, get_position(273, 120));
    cars[index].rect_offset = 546;
    cars[index].rect_max = 1638;
    sfSprite_setTextureRect(cars[index].sprite,
    get_rect(0, 0, 546, 163));
    cars[index].price = 16000;
    cars[index].horse_power = 350;
    cars[index].max_speed = 260;
    cars[index].turbo = 0;
    cars[index].zero_one_hundred = 5;
    cars[index].zero_one_hundred_after_comma = 2;
    cars[index].max_gear = 6;
    cars[index].name = malloc(sizeof(char) * 8);
    cars[index].name = "bel_air";
}

void create_camaro_ss(car_t *cars, int index)
{
    cars[index].texture = sfTexture_createFromFile("files/cars/camaro_ss.png",
    NULL);
    cars[index].sprite = get_sprite(cars[index].texture);
    cars[index].offset = get_position(247, 100);
    sfSprite_setOrigin(cars[index].sprite, get_position(247, 100));
    cars[index].rect_offset = 495;
    cars[index].rect_max = 1485;
    sfSprite_setTextureRect(cars[index].sprite,
    get_rect(0, 0, 495, 139));
    cars[index].price = 6400;
    cars[index].horse_power = 195;
    cars[index].max_speed = 238;
    cars[index].turbo = 0;
    cars[index].zero_one_hundred = 6;
    cars[index].zero_one_hundred_after_comma = 6;
    cars[index].max_gear = 4;
    cars[index].name = malloc(sizeof(char) * 10);
    cars[index].name = "camaro_ss";
}

void create_cobalt(car_t *cars, int index)
{
    cars[index].texture = sfTexture_createFromFile("files/cars/cobalt.png",
    NULL);
    cars[index].sprite = get_sprite(cars[index].texture);
    cars[index].offset = get_position(246, 120);
    sfSprite_setOrigin(cars[index].sprite, get_position(246, 120));
    cars[index].rect_offset = 492;
    cars[index].rect_max = 1476;
    sfSprite_setTextureRect(cars[index].sprite,
    get_rect(0, 0, 492, 160));
    cars[index].price = 7300;
    cars[index].horse_power = 190;
    cars[index].max_speed = 245;
    cars[index].turbo = 0;
    cars[index].zero_one_hundred = 6;
    cars[index].zero_one_hundred_after_comma = 4;
    cars[index].max_gear = 6;
    cars[index].name = malloc(sizeof(char) * 7);
    cars[index].name = "cobalt";
}

void create_cooper(car_t *cars, int index)
{
    cars[index].texture = sfTexture_createFromFile("files/cars/cooper.png",
    NULL);
    cars[index].sprite = get_sprite(cars[index].texture);
    cars[index].offset = get_position(184, 120);
    sfSprite_setOrigin(cars[index].sprite, get_position(184, 120));
    cars[index].rect_offset = 369;
    cars[index].rect_max = 1107;
    sfSprite_setTextureRect(cars[index].sprite,
    get_rect(0, 0, 369, 166));
    cars[index].price = 3200;
    cars[index].horse_power = 150;
    cars[index].max_speed = 190;
    cars[index].turbo = 0;
    cars[index].zero_one_hundred = 9;
    cars[index].zero_one_hundred_after_comma = 2;
    cars[index].max_gear = 4;
    cars[index].name = malloc(sizeof(char) * 6);
    cars[index].name = "cooper";
}
