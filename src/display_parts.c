/*
** EPITECH PROJECT, 2022
** display_parts.c
** File description:
** functions used to display car parts in shop
*/

#include "rpg.h"

static void select_air_part(sfRenderWindow *win, game_t *game)
{
    for (int i = 6; i < 10; ++i) {
        sfRenderWindow_drawSprite(win, game->parts[i].sprite, NULL);
        if (is_button_pressed(game, game->parts[i])) {
            sfSprite_setPosition(game->dealership_buttons[2].sprite,
            get_position(100, 900));
            game->parts->selected = i;
        }
    }
    draw_selected(win, game);
}

void display_air_filters(sfRenderWindow *win, game_t *game)
{
    if (game->parts[5].is_toggled == 1) {
        draw_rect(get_position(50, 700), get_position(1820, 300), 200, win);
        select_air_part(win, game);
        display_text(get_position(350, 730), "Sport Air Filter", 30, win);
        display_text(get_position(590, 800), "$ 249", 20, win);
        display_text(get_position(415, 930), "Power gain: x1.1", 20, win);
        display_text(get_position(685, 730), "Race Air Filter", 30, win);
        display_text(get_position(890, 800), "$ 910", 20, win);
        display_text(get_position(725, 930), "Power gain: x1.15", 20, win);
        display_text(get_position(1035, 730), "Downpipes", 30, win);
        display_text(get_position(1230, 800), "$ 2480", 20, win);
        display_text(get_position(1040, 930), "Power gain: x1.3", 20, win);
        display_text(get_position(1360, 730), "Hood scoop", 30, win);
        display_text(get_position(1590, 800), "$ 4390", 20, win);
        display_text(get_position(1365, 930), "Power gain: x1.5", 20, win);
    }
}

static void select_rad_part(sfRenderWindow *win, game_t *game)
{
    for (int i = 12; i < 16; ++i) {
        sfRenderWindow_drawSprite(win, game->parts[i].sprite, NULL);
        if (is_button_pressed(game, game->parts[i])) {
            sfSprite_setPosition(game->dealership_buttons[2].sprite,
            get_position(100, 900));
            game->parts->selected = i;
        }
    }
    draw_selected(win, game);
}

void display_radiators(sfRenderWindow *win, game_t *game)
{
    if (game->parts[10].is_toggled == 1) {
        draw_rect(get_position(50, 700), get_position(1820, 300), 200, win);
        select_rad_part(win, game);
        display_text(get_position(360, 730), "Sport radiator", 30, win);
        display_text(get_position(590, 800), "$ 150", 20, win);
        display_text(get_position(395, 930), "Power gain: x1.08", 20, win);
        display_text(get_position(740, 730), "Pr radiator", 30, win);
        display_text(get_position(940, 800), "$ 540", 20, win);
        display_text(get_position(755, 930), "Power gain: x1.13", 20, win);
        display_text(get_position(995, 730), "Diamond radiator", 30, win);
        display_text(get_position(1250, 800), "$ 1670", 20, win);
        display_text(get_position(1055, 930), "Power gain: x1.2", 20, win);
        display_text(get_position(1340, 730), "pr racing radiator", 30, win);
        display_text(get_position(1590, 800), "$ 2790", 20, win);
        display_text(get_position(1415, 930), "Power gain: x1.3", 20, win);
    }
}