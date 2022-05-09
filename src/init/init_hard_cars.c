/*
** EPITECH PROJECT, 2022
** init_hard_cars.c
** File description:
** initialize hard cars
*/

#include "rpg.h"

void create_mojang(car_t *cars, int index)
{
    cars[index].texture = sfTexture_createFromFile("files/cars/mojang.png",
    NULL);
    cars[index].sprite = get_sprite(cars[index].texture);
    cars[index].offset = get_position(225, 140);
    sfSprite_setOrigin(cars[index].sprite, get_position(225, 140));
    cars[index].rect_offset = 450;
    cars[index].rect_max = 1350;
    sfSprite_setTextureRect(cars[index].sprite,
    get_rect(0, 0, 450, 184));
    cars[index].price = 4100;
    cars[index].horse_power = 165;
    cars[index].max_speed = 185;
    cars[index].turbo = 0;
    cars[index].zero_one_hundred = 9;
    cars[index].zero_one_hundred_after_comma = 8;
    cars[index].max_gear = 4;
}

void create_rx7(car_t *cars, int index)
{
    cars[index].texture = sfTexture_createFromFile("files/cars/rx7.png",
    NULL);
    cars[index].sprite = get_sprite(cars[index].texture);
    cars[index].offset = get_position(252, 105);
    sfSprite_setOrigin(cars[index].sprite, get_position(252, 105));
    cars[index].rect_offset = 504;
    cars[index].rect_max = 1512;
    sfSprite_setTextureRect(cars[index].sprite,
    get_rect(0, 0, 504, 136));
    cars[index].price = 25600;
    cars[index].horse_power = 430;
    cars[index].max_speed = 320;
    cars[index].turbo = 1;
    cars[index].zero_one_hundred = 4;
    cars[index].zero_one_hundred_after_comma = 9;
    cars[index].max_gear = 5;
}

void create_z76(car_t *cars, int index)
{
    cars[index].texture = sfTexture_createFromFile("files/cars/z76.png",
    NULL);
    cars[index].sprite = get_sprite(cars[index].texture);
    cars[index].offset = get_position(259, 100);
    sfSprite_setOrigin(cars[index].sprite, get_position(259, 100));
    cars[index].rect_offset = 519;
    cars[index].rect_max = 1557;
    sfSprite_setTextureRect(cars[index].sprite,
    get_rect(0, 0, 519, 139));
    cars[index].price = 9300;
    cars[index].horse_power = 240;
    cars[index].max_speed = 260;
    cars[index].turbo = 0;
    cars[index].zero_one_hundred = 6;
    cars[index].zero_one_hundred_after_comma = 2;
    cars[index].max_gear = 4;
}

void create_silvia(car_t *cars, int index)
{
    cars[index].texture = sfTexture_createFromFile("files/cars/silvia.png",
    NULL);
    cars[index].sprite = get_sprite(cars[index].texture);
    cars[index].offset = get_position(262.5, 110);
    sfSprite_setOrigin(cars[index].sprite, get_position(262.5, 110));
    cars[index].rect_offset = 525;
    cars[index].rect_max = 1575;
    sfSprite_setTextureRect(cars[index].sprite,
    get_rect(0, 0, 525, 148));
    cars[index].price = 36000;
    cars[index].horse_power = 460;
    cars[index].max_speed = 320;
    cars[index].turbo = 1;
    cars[index].zero_one_hundred = 4;
    cars[index].zero_one_hundred_after_comma = 0;
    cars[index].max_gear = 6;
}

void create_supra(car_t *cars, int index)
{
    cars[index].texture = sfTexture_createFromFile("files/cars/supra.png",
    NULL);
    cars[index].sprite = get_sprite(cars[index].texture);
    cars[index].offset = get_position(268.5, 110);
    sfSprite_setOrigin(cars[index].sprite, get_position(268.5, 110));
    cars[index].rect_offset = 537;
    cars[index].rect_max = 1611;
    sfSprite_setTextureRect(cars[index].sprite,
    get_rect(0, 0, 537, 148));
    cars[index].price = 52000;
    cars[index].horse_power = 550;
    cars[index].max_speed = 360;
    cars[index].turbo = 1;
    cars[index].zero_one_hundred = 3;
    cars[index].zero_one_hundred_after_comma = 6;
    cars[index].max_gear = 5;
}
