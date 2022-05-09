/*
** EPITECH PROJECT, 2022
** car_handling
** File description:
** functions used to handle cars in their globality
*/

#include <stdlib.h>
#include "rpg.h"
#include "my.h"

void transfer_car_to_garage(game_t *game, car_t *garage, car_t car, int i)
{
    garage[i].texture = sfSprite_getTexture(car.sprite);
    garage[i].sprite = get_sprite(garage[i].texture);
    garage[i].speed = car.speed;
    garage[i].price = car.price;
    garage[i].rect = sfSprite_getTextureRect(car.sprite);
    garage[i].rect_max = car.rect_max;
    garage[i].rect_offset = car.rect_offset;
    garage[i].offset = car.offset;
    garage[i].max_speed = car.max_speed;
    garage[i].horse_power = car.horse_power;
    garage[i].turbo = car.turbo;
    garage[i].zero_one_hundred = car.zero_one_hundred;
    garage[i].max_gear = car.max_gear;
    garage[i].nb_items = 0;
    garage[i].item_selected = -1;
    garage[i].zero_one_hundred_after_comma = car.zero_one_hundred_after_comma;
    game->car_is_bought = 1;
    sfSprite_setOrigin(garage[i].sprite, sfSprite_getOrigin(car.sprite));
    sfSprite_setTextureRect(garage[i].sprite,
    sfSprite_getTextureRect(car.sprite));
}

void put_car_in_garage(game_t *game, car_t car)
{
    car_t *new_garage = malloc((game->garage->nb_cars + 1) * sizeof(car_t));

    for (int i = 0; i < game->garage->nb_cars;++i)
        transfer_car_to_garage(game, new_garage, game->garage[i], i);
    new_garage->nb_cars = game->garage->nb_cars + 1;
    transfer_car_to_garage(game, new_garage, car, game->garage->nb_cars);
    game->garage = new_garage;
    game->money -= car.price;
    game->money_spend += car.price;
}

void set_current_car(game_t *game, car_t car, int pos)
{
    game->current_car.max_speed = car.max_speed;
    game->current_car.horse_power = car.horse_power;
    game->current_car.turbo = car.turbo;
    game->current_car.zero_one_hundred = car.zero_one_hundred;
    game->current_car.zero_one_hundred_after_comma =
    car.zero_one_hundred_after_comma;
    game->current_car.texture = sfSprite_getTexture(car.sprite);
    game->current_car.sprite = get_sprite(game->current_car.texture);
    sfClock_restart(game->current_car.anim);
    game->current_car.rect_offset = car.rect_offset;
    game->current_car.rect_max = car.rect_max;
    game->current_car.max_gear = car.max_gear;
    game->current_car.item_selected = -1; game->current_car.price = car.price;
    game->current_car.garage_pos = pos; game->current_car.items = car.items;
    game->current_car.nb_items = car.nb_items;
    sfSprite_setPosition(game->current_car.sprite, get_position(960, 590));
    sfSprite_setOrigin(game->current_car.sprite, car.offset);
    sfSprite_setTextureRect(game->current_car.sprite,
    sfSprite_getTextureRect(car.sprite));
    sfSprite_setScale(game->current_car.sprite, get_position(0.7, 0.7));
}
