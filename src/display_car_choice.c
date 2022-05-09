/*
** EPITECH PROJECT, 2022
** display_car_choice
** File description:
** functions used to choose starter car
*/

#include "rpg.h"

void display_car_choice(sfRenderWindow *window, game_t *game)
{
    display_window(window);
    sfRenderWindow_drawSprite(window, game->backgrounds[1].sprite, NULL);
    display_text(get_position(85, 100), "CHOOSE YOUR CAR:", 200, window);
    draw_rect(get_position(50, 500), get_position(1820, 300), 180, window);
    for (int i = 0; i < 2; ++i) {
        sfSprite_setPosition(game->cars[i].sprite,
        get_position(600 * i + 300, 650));
        sfRenderWindow_drawSprite(window, game->cars[i].sprite, NULL);
    }
    sfSprite_setPosition(game->cars[2].sprite,
    get_position(1250 + 300, 650));
    sfRenderWindow_drawSprite(window, game->cars[2].sprite, NULL);
    display_text(get_position(140, 700), "Peugeot 205", 50, window);
    display_text(get_position(750, 700), "Peugeot 206", 50, window);
    display_text(get_position(1410, 700), "Honda Civic", 50, window);
}
