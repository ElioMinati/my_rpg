/*
** EPITECH PROJECT, 2022
** create_beginner_cars.c
** File description:
** initialize beginner cars
*/

#include "rpg.h"

void create_e36(car_t *cars, int index)
{
    cars[index].texture = sfTexture_createFromFile("files/cars/e36.png",
    NULL);
    cars[index].sprite = get_sprite(cars[index].texture);
    cars[index].offset = get_position(252, 110);
    sfSprite_setOrigin(cars[index].sprite, get_position(252, 110));
    cars[index].rect_offset = 504;
    cars[index].rect_max = 1512;
    sfSprite_setTextureRect(cars[index].sprite,
    get_rect(0, 0, 504, 154));
    cars[index].price = 7200;
    cars[index].horse_power = 185;
    cars[index].max_speed = 258;
    cars[index].turbo = 1;
    cars[index].zero_one_hundred = 7;
    cars[index].zero_one_hundred_after_comma = 5;
    cars[index].max_gear = 6;
    cars[index].name = malloc(sizeof(char) * 4);
    cars[index].name = "e36";
}

void create_e92(car_t *cars, int index)
{
    cars[index].texture = sfTexture_createFromFile("files/cars/e92.png",
    NULL);
    cars[index].sprite = get_sprite(cars[index].texture);
    cars[index].offset = get_position(255, 120);
    sfSprite_setOrigin(cars[index].sprite, get_position(255, 120));
    cars[index].rect_offset = 510;
    cars[index].rect_max = 1530;
    sfSprite_setTextureRect(cars[index].sprite,
    get_rect(0, 0, 510, 160));
    cars[index].price = 12200;
    cars[index].horse_power = 245;
    cars[index].max_speed = 300;
    cars[index].turbo = 1;
    cars[index].zero_one_hundred = 5;
    cars[index].zero_one_hundred_after_comma = 3;
    cars[index].max_gear = 6;
    cars[index].name = malloc(sizeof(char) * 4);
    cars[index].name = "e92";
}

void create_golf(car_t *cars, int index)
{
    cars[index].texture = sfTexture_createFromFile("files/cars/golf.png",
    NULL);
    cars[index].sprite = get_sprite(cars[index].texture);
    cars[index].offset = get_position(240, 110);
    sfSprite_setOrigin(cars[index].sprite, get_position(240, 110));
    cars[index].rect_offset = 480;
    cars[index].rect_max = 1440;
    sfSprite_setTextureRect(cars[index].sprite,
    get_rect(0, 0, 480, 160));
    cars[index].price = 4000;
    cars[index].horse_power = 160;
    cars[index].max_speed = 230;
    cars[index].turbo = 0;
    cars[index].zero_one_hundred = 8;
    cars[index].zero_one_hundred_after_comma = 6;
    cars[index].max_gear = 5;
    cars[index].name = malloc(sizeof(char) * 5);
    cars[index].name = "golf";
}

void create_is200(car_t *cars, int index)
{
    cars[index].texture = sfTexture_createFromFile("files/cars/is200.png",
    NULL);
    cars[index].sprite = get_sprite(cars[index].texture);
    cars[index].offset = get_position(255, 120);
    sfSprite_setOrigin(cars[index].sprite, get_position(255, 120));
    cars[index].rect_offset = 510;
    cars[index].rect_max = 1530;
    sfSprite_setTextureRect(cars[index].sprite,
    get_rect(0, 0, 510, 160));
    cars[index].price = 10700;
    cars[index].horse_power = 225;
    cars[index].max_speed = 260;
    cars[index].turbo = 1;
    cars[index].zero_one_hundred = 5;
    cars[index].zero_one_hundred_after_comma = 4;
    cars[index].max_gear = 5;
    cars[index].name = malloc(sizeof(char) * 6);
    cars[index].name = "is200";
}
