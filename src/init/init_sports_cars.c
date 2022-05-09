/*
** EPITECH PROJECT, 2022
** init_sports_cars.c
** File description:
** functions used to initalize sport cars used in game
*/

#include "rpg.h"

void create_crx(car_t *cars, int index)
{
    cars[index].texture = sfTexture_createFromFile("files/cars/crx.png",
    NULL);
    cars[index].sprite = get_sprite(cars[index].texture);
    cars[index].offset = get_position(223, 105);
    sfSprite_setOrigin(cars[index].sprite, get_position(223, 105));
    cars[index].rect_offset = 447;
    cars[index].rect_max = 1341;
    sfSprite_setTextureRect(cars[index].sprite,
    get_rect(0, 0, 447, 151));
    cars[index].price = 3500;
    cars[index].horse_power = 157;
    cars[index].max_speed = 219;
    cars[index].turbo = 0;
    cars[index].zero_one_hundred = 8;
    cars[index].zero_one_hundred_after_comma = 2;
    cars[index].max_gear = 5;
    cars[index].name = malloc(sizeof(char) * 4);
    cars[index].name = "crx";
}

void create_180sx(car_t *cars, int index)
{
    cars[index].texture = sfTexture_createFromFile("files/cars/180sx.png",
    NULL);
    cars[index].sprite = get_sprite(cars[index].texture);
    cars[index].offset = get_position(258, 110);
    sfSprite_setOrigin(cars[index].sprite, get_position(258, 110));
    cars[index].rect_offset = 516;
    cars[index].rect_max = 1548;
    sfSprite_setTextureRect(cars[index].sprite,
    get_rect(0, 0, 516, 145));
    cars[index].price = 8500;
    cars[index].horse_power = 215;
    cars[index].max_speed = 245;
    cars[index].turbo = 1;
    cars[index].zero_one_hundred = 7;
    cars[index].zero_one_hundred_after_comma = 6;
    cars[index].max_gear = 5;
    cars[index].name = malloc(sizeof(char) * 6);
    cars[index].name = "180sx";
}

void create_350z(car_t *cars, int index)
{
    cars[index].texture = sfTexture_createFromFile("files/cars/350z.png",
    NULL);
    cars[index].sprite = get_sprite(cars[index].texture);
    cars[index].offset = get_position(244, 110);
    sfSprite_setOrigin(cars[index].sprite, get_position(244, 110));
    cars[index].rect_offset = 489;
    cars[index].rect_max = 1467;
    sfSprite_setTextureRect(cars[index].sprite,
    get_rect(0, 0, 489, 148));
    cars[index].price = 13600;
    cars[index].horse_power = 285;
    cars[index].max_speed = 292;
    cars[index].turbo = 0;
    cars[index].zero_one_hundred = 6;
    cars[index].zero_one_hundred_after_comma = 3;
    cars[index].max_gear = 6;
    cars[index].name = malloc(sizeof(char) * 5);
    cars[index].name = "350z";
}

void create_850r(car_t *cars, int index)
{
    cars[index].texture = sfTexture_createFromFile("files/cars/850r.png",
    NULL);
    cars[index].sprite = get_sprite(cars[index].texture);
    cars[index].offset = get_position(255, 120);
    sfSprite_setOrigin(cars[index].sprite, get_position(255, 120));
    cars[index].rect_offset = 510;
    cars[index].rect_max = 1530;
    sfSprite_setTextureRect(cars[index].sprite,
    get_rect(0, 0, 510, 169));
    cars[index].price = 4200;
    cars[index].horse_power = 155;
    cars[index].max_speed = 225;
    cars[index].turbo = 0;
    cars[index].zero_one_hundred = 8;
    cars[index].zero_one_hundred_after_comma = 3;
    cars[index].max_gear = 6;
    cars[index].name = malloc(sizeof(char) * 5);
    cars[index].name = "850r";
}
