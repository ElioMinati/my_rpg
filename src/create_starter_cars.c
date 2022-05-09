/*
** EPITECH PROJECT, 2022
** create_starter_cars
** File description:
** functions used to create unique cars
*/

#include "rpg.h"

void create_205(car_t *cars, int index)
{
    cars[index].texture = sfTexture_createFromFile("files/cars/205.png",
    NULL);
    cars[index].sprite = get_sprite(cars[index].texture);
    cars[index].offset = get_position(200, 120);
    sfSprite_setOrigin(cars[index].sprite, get_position(200, 120));
    cars[index].rect_offset = 410;
    cars[index].rect_max = 1230;
    sfSprite_setTextureRect(cars[index].sprite, get_rect(0, 0, 410, 162));
    cars[index].price = 2000;
    cars[index].horse_power = 130;
    cars[index].max_speed = 215;
    cars[index].turbo = 0;
    cars[index].zero_one_hundred = 9;
    cars[index].zero_one_hundred_after_comma = 4;
    cars[index].max_gear = 5;
    cars[index].name = malloc(sizeof(char) * 4);
    cars[index].name = "205";
}

void create_206(car_t *cars, int index)
{
    cars[index].texture = sfTexture_createFromFile("files/cars/206.png",
    NULL);
    cars[index].sprite = get_sprite(cars[index].texture);
    cars[index].offset = get_position(200, 120);
    sfSprite_setOrigin(cars[index].sprite, get_position(200, 120));
    cars[index].rect_offset = 430;
    cars[index].rect_max = 1270;
    sfSprite_setTextureRect(cars[index].sprite,
    get_rect(0, 0, 430, 165));
    cars[index].price = 2500;
    cars[index].horse_power = 138;
    cars[index].max_speed = 205;
    cars[index].turbo = 0;
    cars[index].zero_one_hundred = 8;
    cars[index].zero_one_hundred_after_comma = 9;
    cars[index].max_gear = 6;
    cars[index].name = malloc(sizeof(char) * 4);
    cars[index].name = "206";
}

void create_civic(car_t *cars, int index)
{
    cars[index].texture = sfTexture_createFromFile(
    "files/cars/civic.png", NULL);
    cars[index].sprite = get_sprite(cars[index].texture);
    cars[index].offset = get_position(230, 123);
    sfSprite_setOrigin(cars[index].sprite, get_position(230, 123));
    cars[index].rect_offset = 490;
    cars[index].rect_max = 1470;
    sfSprite_setTextureRect(cars[index].sprite,
    get_rect(0, 0, 490, 166));
    cars[index].price = 3000;
    cars[index].horse_power = 145;
    cars[index].max_speed = 200;
    cars[index].turbo = 0;
    cars[index].zero_one_hundred = 7;
    cars[index].zero_one_hundred_after_comma = 6;
    cars[index].max_gear = 5;
    cars[index].name = malloc(sizeof(char) * 6);
    cars[index].name = "civic";
}
