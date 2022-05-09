/*
** EPITECH PROJECT, 2022
** init_more_boss_cars
** File description:
** functions used to create a boss car
*/

#include "rpg.h"
#include "my.h"

void create_boss_r8(car_t *cars, int index)
{
    cars[index].texture = sfTexture_createFromFile("files/cars/boss_r8.png",
    NULL);
    cars[index].sprite = get_sprite(cars[index].texture);
    cars[index].offset = get_position(250, 110);
    sfSprite_setOrigin(cars[index].sprite, get_position(250, 110));
    cars[index].rect_offset = 501;
    cars[index].rect_max = 1503;
    sfSprite_setTextureRect(cars[index].sprite, get_rect(0, 0, 501, 139));
    cars[index].price = 2000;
    cars[index].horse_power = 500;
    cars[index].max_speed = 315;
    cars[index].turbo = 0;
    cars[index].eliminated = 0;
    cars[index].zero_one_hundred = 5;
    cars[index].zero_one_hundred_after_comma = 0;
    cars[index].name = my_strdup("Certified Coomer") ;
}

void create_boss_lfa(car_t *cars, int index)
{
    cars[index].texture = sfTexture_createFromFile("files/cars/boss_lfa.png",
    NULL);
    cars[index].sprite = get_sprite(cars[index].texture);
    cars[index].offset = get_position(253, 110);
    sfSprite_setOrigin(cars[index].sprite, get_position(253, 110));
    cars[index].rect_offset = 507;
    cars[index].rect_max = 1521;
    sfSprite_setTextureRect(cars[index].sprite, get_rect(0, 0, 507, 142));
    cars[index].price = 2000;
    cars[index].horse_power = 680;
    cars[index].max_speed = 370;
    cars[index].turbo = 0;
    cars[index].eliminated = 0;
    cars[index].zero_one_hundred = 4;
    cars[index].zero_one_hundred_after_comma = 0;
    cars[index].name = my_strdup("Mathis Mathis");
}
