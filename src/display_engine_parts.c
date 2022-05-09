/*
** EPITECH PROJECT, 2022
** display_engine_parts.c
** File description:
** functions used to display engine parts
*/

#include "rpg.h"

static void select_pis_part(sfRenderWindow *win, game_t *game)
{
    for (int i = 17; i < 20; ++i) {
        sfRenderWindow_drawSprite(win, game->parts[i].sprite, NULL);
        if (is_button_pressed(game, game->parts[i])) {
            sfSprite_setPosition(game->dealership_buttons[2].sprite,
            get_position(100, 900));
            game->parts->selected = i;
        }
    }
    draw_selected(win, game);
}

void display_pistons(sfRenderWindow *win, game_t *game)
{
    if (game->parts[16].is_toggled == 1) {
        draw_rect(get_position(50, 700), get_position(1820, 300), 200, win);
        select_pis_part(win, game);
        display_text(get_position(340, 730), "Reinforced pistons", 30, win);
        display_text(get_position(570, 800), "$ 2470", 20, win);
        display_text(get_position(395, 940), "Power gain: x1.08", 20, win);
        display_text(get_position(810, 730), "forged pistons", 30, win);
        display_text(get_position(1010, 800), "$ 5600", 20, win);
        display_text(get_position(850, 940), "Power gain: x1.13", 20, win);
        display_text(get_position(1260, 730), "Golden Coated pistons", 30, win);
        display_text(get_position(1450, 800), "$ 7930", 20, win);
        display_text(get_position(1300, 940), "Power gain: x1.2", 20, win);
    }
}

static void select_carto_part(sfRenderWindow *win, game_t *game)
{
    for (int i = 21; i < 25; ++i) {
        sfRenderWindow_drawSprite(win, game->parts[i].sprite, NULL);
        if (is_button_pressed(game, game->parts[i])) {
            sfSprite_setPosition(game->dealership_buttons[2].sprite,
            get_position(100, 900));
            game->parts->selected = i;
        }
    }
    draw_selected(win, game);
}

void display_cartos(sfRenderWindow *win, game_t *game)
{
    if (game->parts[20].is_toggled == 1) {
        draw_rect(get_position(50, 700), get_position(1820, 300), 200, win);
        select_carto_part(win, game);
        display_text(get_position(420, 730), "2 step map", 30, win);
        display_text(get_position(580, 800), "$ 710", 20, win);
        display_text(get_position(410, 940), "Power gain: x1.09", 20, win);
        display_text(get_position(730, 730), "Sport map", 30, win);
        display_text(get_position(880, 800), "$ 1340", 20, win);
        display_text(get_position(720, 940), "Power gain: x1.14", 20, win);
        display_text(get_position(1010, 730), "Type R map", 30, win);
        display_text(get_position(1170, 800), "$ 3450", 20, win);
        display_text(get_position(1015, 940), "Power gain: x1.25", 20, win);
        display_text(get_position(1280, 730), "Type R 2 step map", 30, win);
        display_text(get_position(1470, 800), "$ 4290", 20, win);
        display_text(get_position(1315, 940), "Power gain: x1.35", 20, win);
    }
}
