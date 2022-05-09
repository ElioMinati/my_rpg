/*
** EPITECH PROJECT, 2022
** display_dealership.c
** File description:
** functions used to display the dealership
*/

#include "rpg.h"
#include "my.h"

static void display_dealer_stats(sfRenderWindow *win, game_t *game, int cur_car)
{
    display_text(get_position(1230, 780), my_strcat("HP: ",
    my_itoa(game->cars[cur_car].horse_power)), 40, win);
    display_text(get_position(1230, 830), my_strcat(
    my_strcat(my_strcat(my_strcat("0-100: ",
    my_itoa(game->cars[cur_car].zero_one_hundred)), "."),
    my_itoa(game->cars[cur_car].zero_one_hundred_after_comma)), " s"), 40, win);
    display_text(get_position(1230, 880), my_strcat("Max speed: ",
    my_itoa(game->cars[cur_car].max_speed)), 40, win);
    if (game->cars[cur_car].turbo == 0)
        display_text(get_position(1230, 930), "Turbo: No", 40, win);
    else
        display_text(get_position(1230, 930), "Turbo: Yes", 40, win);
    if (is_button_hovered(win, game, game->dealership_buttons[2]))
        draw_rect(sfSprite_getPosition(game->dealership_buttons[2].sprite),
        get_position(200, 70), 100, win);
    display_money(win, game);
    display_xp(game, win);
    manage_return(win, game);
}

void display_dealership(sfRenderWindow *win, game_t *game)
{
    int cur_car = get_dealership_car(game->cars);

    handle_dealership_events(game, win);
    display_window(win);
    sfRenderWindow_drawSprite(win, game->backgrounds[5].sprite, NULL);
    for (int i = 0; i < game->cars->nb_cars; ++i) {
        sfRenderWindow_drawSprite(win, game->cars[i].sprite, NULL);
    }
    for (int i = 0; i < game->dealership_buttons->nb_buttons; ++i)
        sfRenderWindow_drawSprite(win, game->dealership_buttons[i].sprite,
        NULL);
    draw_rect(get_position(1200, 700), get_position(600, 300), 100, win);
    if (game->cars[cur_car].price > game->money)
        display_red_text(get_position(1230, 720), my_strcat("$ ",
        my_itoa(game->cars[cur_car].price)), 50, win);
    else
        display_green_text(get_position(1230, 720), my_strcat("$ ",
        my_itoa(game->cars[cur_car].price)), 50, win);
    display_dealer_stats(win, game, cur_car);
}
