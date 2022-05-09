/*
** EPITECH PROJECT, 2022
** display_inventory.c
** File description:
** functions used to display the inventory
*/

#include "rpg.h"
#include "my.h"

static void display_inv_items(sfRenderWindow *window, game_t *game,
char *turbo, char *zth)
{
    if (game->scene == 2) {
        sfRenderWindow_drawSprite(window, game->inventory.sprite, NULL);
        display_player_stats(window, game);
        display_text(get_position(525, 640), "CAR STATS", 50, window);
        display_text(get_position(430, 710), my_strcat("hp: ",
        my_itoa(game->current_car.horse_power)), 40, window);
        display_text(get_position(430, 765),
        my_strcat("0-100: ", zth), 40, window);
        display_text(get_position(590, 710), my_strcat("max speed: ",
        my_itoa(game->current_car.max_speed)), 40, window);
        display_text(get_position(640, 765),
        my_strcat("turbo: ", turbo), 40, window);
    } else {
        display_alt_inv(window);
        if (game->error_clock.error == 3)
            display_error_message(get_position(680, 130),
            "Item of same type already equiped", game, window);
    }
    display_item(window, game);
}

void display_inventory(sfRenderWindow *window, game_t *game)
{
    char *turbo = NULL;
    char *zth = my_strcat(
    my_itoa(game->current_car.zero_one_hundred), ",");

    zth = my_strcat(zth,
    my_itoa(game->current_car.zero_one_hundred_after_comma));
    if (game->current_car.turbo == 0) {
        turbo = "NO";
    } else {
        turbo = "YES";
    }
    display_inv_items(window, game, turbo, zth);
}
