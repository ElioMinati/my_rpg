/*
** EPITECH PROJECT, 2022
** init_cars
** File description:
** initialise cars in various ways
*/

#include "rpg.h"

void init_speedlist(game_t *game)
{
    game->main_buttons[8].texture = sfTexture_createFromFile(
    "files/buttons/speedlist.png", NULL);
    game->main_buttons[8].sprite = get_sprite(game->main_buttons[8].texture);
    sfSprite_setPosition(game->main_buttons[8].sprite,
    get_position(1780, 0));
    sfSprite_setScale(game->main_buttons[8].sprite, get_position(1, 1));
    sfSprite_setTextureRect(game->main_buttons[8].sprite,
    get_rect(0, 0, 136, 88));
    game->main_buttons[8].is_toggled = 0;
    game->main_buttons[9].texture = sfTexture_createFromFile(
    "files/buttons/challenge_button.png", NULL);
    game->main_buttons[9].sprite = get_sprite(game->main_buttons[9].texture);
    sfSprite_setTextureRect(game->main_buttons[9].sprite,
    get_rect(0, 0, 177, 43));
}

static void create_boss_cars(game_t *game)
{
    game->speedlist = malloc(7 * sizeof(car_t));
    create_boss_r8(game->speedlist, 0);
    create_boss_r35(game->speedlist, 1);
    create_boss_lfa(game->speedlist, 2);
    create_boss_challenger(game->speedlist, 3);
    create_boss_skyline(game->speedlist, 4);
    create_boss_civic(game->speedlist, 5);
    create_boss_bttf(game->speedlist, 6);
    init_speedlist(game);
}

void create_cars(game_t *game)
{
    int x = -200;
    game->cars = malloc(20 * sizeof(car_t));
    game->cars->nb_cars = 20;
    init_all_cars(game);
    for (int i = 0; i < game->cars->nb_cars; ++i) {
        sfSprite_setPosition(game->cars[i].sprite,
        get_position(x, 700));
        sfSprite_setScale(game->cars[i].sprite,
        get_position(1.6, 1.6));
        x += 1150;
    }
    create_boss_cars(game);
    init_inv_buttons(game);
    game->particles.clock.clock = sfClock_create();
    game->current_car.nb_items = 0;
}

void init_garage_arrows(button_t *buttons)
{
    buttons[5].is_pressed = 0;
    buttons[5].rect = get_rect(0, 0, 324, 450);
    buttons[5].texture = sfTexture_createFromFile(
    "files/buttons/arrow.png", NULL);
    buttons[5].sprite = get_sprite(buttons[5].texture);
    sfSprite_setScale(buttons[5].sprite, get_position(0.3, 0.3));
    sfSprite_setTextureRect(buttons[5].sprite, buttons[5].rect);
    sfSprite_setPosition(buttons[5].sprite, get_position(30, 500));
    buttons[5].is_toggled = 0;
    buttons[6].is_pressed = 0;
    buttons[6].rect = get_rect(0, 0, 324, 450);
    buttons[6].texture = sfTexture_createFromFile(
    "files/buttons/arrow.png", NULL);
    buttons[6].sprite = get_sprite(buttons[6].texture);
    sfSprite_setScale(buttons[6].sprite, get_position(-0.3, 0.3));
    sfSprite_setTextureRect(buttons[6].sprite, buttons[6].rect);
    sfSprite_setPosition(buttons[6].sprite, get_position(1870, 500));
    buttons[6].is_toggled = 0;
}

void create_garage_button(button_t *buttons)
{
    buttons[4].is_pressed = 0;
    buttons[4].rect = get_rect(0, 0, 178, 142);
    buttons[4].texture = sfTexture_createFromFile(
    "files/buttons/garage.png", NULL);
    buttons[4].sprite = get_sprite(buttons[4].texture);
    sfSprite_setTextureRect(buttons[4].sprite, buttons[4].rect);
    sfSprite_setPosition(buttons[4].sprite, get_position(70, 800));
    buttons[4].is_toggled = 0;
    init_garage_arrows(buttons);
    buttons[11].texture = sfTexture_createFromFile(
    "files/buttons/skip.png", NULL);
    buttons[11].sprite = get_sprite(buttons[11].texture);
    sfSprite_setPosition(buttons[11].sprite, get_position(1800, 20));
    sfSprite_setTextureRect(buttons[11].sprite, get_rect(0, 0, 85, 40));
    buttons[11].is_toggled = 0;
}
