/*
** EPITECH PROJECT, 2022
** init_boss_cars
** File description:
** functions used to initialize boss cars
*/

#include "rpg.h"
#include "my.h"

void create_boss_skyline(car_t *cars, int index)
{
    cars[index].texture = sfTexture_createFromFile(
    "files/cars/boss_skyline.png", NULL);
    cars[index].sprite = get_sprite(cars[index].texture);
    cars[index].offset = get_position(250, 120);
    sfSprite_setOrigin(cars[index].sprite, get_position(250, 120));
    cars[index].rect_offset = 501;
    cars[index].rect_max = 1503;
    sfSprite_setTextureRect(cars[index].sprite, get_rect(0, 0, 501, 144));
    cars[index].price = 2000;
    cars[index].horse_power = 950;
    cars[index].max_speed = 380;
    cars[index].turbo = 1;
    cars[index].eliminated = 0;
    cars[index].zero_one_hundred = 3;
    cars[index].zero_one_hundred_after_comma = 3;
    cars[index].name = my_strdup("Eliostututu");
}

void create_boss_civic(car_t *cars, int index)
{
    cars[index].texture = sfTexture_createFromFile("files/cars/boss_civic.png",
    NULL);
    cars[index].sprite = get_sprite(cars[index].texture);
    cars[index].offset = get_position(267, 140);
    sfSprite_setOrigin(cars[index].sprite, get_position(267, 140));
    cars[index].rect_offset = 534;
    cars[index].rect_max = 1602;
    sfSprite_setTextureRect(cars[index].sprite, get_rect(0, 0, 534, 159));
    cars[index].price = 2000;
    cars[index].horse_power = 830;
    cars[index].max_speed = 310;
    cars[index].turbo = 0;
    cars[index].eliminated = 0;
    cars[index].zero_one_hundred = 3;
    cars[index].zero_one_hundred_after_comma = 5;
    cars[index].name = my_strdup("Pierrick Psartek");
}

void create_boss_bttf(car_t *cars, int index)
{
    cars[index].texture = sfTexture_createFromFile("files/cars/boss_bttf.png",
    NULL);
    cars[index].sprite = get_sprite(cars[index].texture);
    cars[index].offset = get_position(240, 120);
    sfSprite_setOrigin(cars[index].sprite, get_position(240, 120));
    cars[index].rect_offset = 480;
    cars[index].rect_max = 1440;
    sfSprite_setTextureRect(cars[index].sprite, get_rect(0, 0, 480, 153));
    cars[index].price = 2000;
    cars[index].horse_power = 1230;
    cars[index].max_speed = 420;
    cars[index].turbo = 1;
    cars[index].eliminated = 0;
    cars[index].zero_one_hundred = 3;
    cars[index].zero_one_hundred_after_comma = 2;
    cars[index].name = my_strdup("Adrian l'aberrant");
}

void create_boss_challenger(car_t *cars, int index)
{
    cars[index].texture = sfTexture_createFromFile(
    "files/cars/boss_challenger.png", NULL);
    cars[index].sprite = get_sprite(cars[index].texture);
    cars[index].offset = get_position(300, 140);
    sfSprite_setOrigin(cars[index].sprite, get_position(300, 140));
    cars[index].rect_offset = 600;
    cars[index].rect_max = 1800;
    sfSprite_setTextureRect(cars[index].sprite, get_rect(0, 0, 600, 168));
    cars[index].price = 2000;
    cars[index].horse_power = 750;
    cars[index].max_speed = 340;
    cars[index].turbo = 1;
    cars[index].eliminated = 0;
    cars[index].zero_one_hundred = 3;
    cars[index].zero_one_hundred_after_comma = 8;
    cars[index].name = my_strdup("Tyoutnan");
}

void create_boss_r35(car_t *cars, int index)
{
    cars[index].texture = sfTexture_createFromFile("files/cars/boss_r35.png",
    NULL);
    cars[index].sprite = get_sprite(cars[index].texture);
    cars[index].offset = get_position(252, 115);
    sfSprite_setOrigin(cars[index].sprite, get_position(252, 120));
    cars[index].rect_offset = 504;
    cars[index].rect_max = 1512;
    sfSprite_setTextureRect(cars[index].sprite, get_rect(0, 0, 504, 136));
    cars[index].price = 2000;
    cars[index].horse_power = 570;
    cars[index].max_speed = 330;
    cars[index].turbo = 1;
    cars[index].eliminated = 0;
    cars[index].zero_one_hundred = 4;
    cars[index].zero_one_hundred_after_comma = 2;
    cars[index].name = my_strdup("Leandre la derkha");
}