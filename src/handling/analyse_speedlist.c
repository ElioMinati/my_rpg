/*
** EPITECH PROJECT, 2022
** analyse_speedlist.c
** File description:
** functions used to analyse speedlist events
*/

#include "rpg.h"
#include "my.h"

static void display_names(sfRenderWindow *win)
{
    display_text(get_position(1087, 185), "certified coomer", 22, win);
    display_text(get_position(1150, 295), "Leand", 22, win);
    display_text(get_position(1105, 405), "mathis mathis", 22, win);
    display_text(get_position(1083, 515), "tyoutan chaiznaut", 22, win);
    display_text(get_position(1132, 625), "eliotstututu", 22, win);
    display_text(get_position(1092, 735), "Pierrick le bg psartek", 22, win);
    display_text(get_position(1083, 845), "L'aberrant Adrian", 22, win);
}

static void display_challenge(game_t *game, sfRenderWindow *win, int i)
{
    int x = 270;

    if (game->speedlist[i].eliminated == 0) {
        sfSprite_setPosition(game->main_buttons[9].sprite,
        get_position(1100, x + 110 * i - 43));
        if (is_button_pressed(game, game->main_buttons[9]))
            init_challenge(game, win, i);
        else
            sfSprite_setTextureRect(game->main_buttons[9].sprite,
            get_rect(0, 0, 177, 43));
        sfRenderWindow_drawSprite(win, game->main_buttons[9].sprite, NULL);
        if (is_button_hovered(win, game, game->main_buttons[9]))
            draw_rect(get_position(1100, x + 110 * i - 43), get_position(177, 43), 100, win);
    } else {
        display_red_text(get_position(1100, x + 110 * i - 43),
        "Eliminated", 30, win);
    }
}

static void display_all_boss_cars(game_t *game, sfRenderWindow *win)
{
    int x = 270;

    for (int i = 0; i < 7; ++i) {
        display_text(get_position(650, x + 110 * i - 70),
        my_itoa(7 - i), 60, win);
        sfSprite_setScale(game->speedlist[i].sprite, get_position(0.6, 0.6));
        sfSprite_setPosition(game->speedlist[i].sprite,
        get_position(900, x + i * 110));
        sfRenderWindow_drawSprite(win, game->speedlist[i].sprite, NULL);
        display_challenge(game, win, i);
    }
    display_names(win);
}

static void analyse_speedlist_hover(game_t *game, sfRenderWindow *win)
{
    if (is_button_hovered(win, game, game->main_buttons[8]))
        sfSprite_setTextureRect(game->main_buttons[8].sprite,
        get_rect(88, 0, 136, 88));
    else
        sfSprite_setTextureRect(game->main_buttons[8].sprite,
        get_rect(0, 0, 136, 88));
}

void analyse_speedlist_events(game_t *game, sfVector2i mouse,
sfRenderWindow *win)
{
    analyse_speedlist_hover(game, win);
    if (is_button_pressed(game, game->main_buttons[8])) {
        if (game->main_buttons[8].is_toggled == 0) {
            game->main_buttons[8].is_toggled = 1;
            sfSprite_setTextureRect(game->main_buttons[8].sprite,
            get_rect(176, 0, 136, 88));
        }
        else {
            game->main_buttons[8].is_toggled = 0;
            sfSprite_setTextureRect(game->main_buttons[8].sprite,
            get_rect(176, 0, 136, 88));
        }
    }
    if (game->main_buttons[8].is_toggled == 1) {
        draw_rect(get_position(600, 50), get_position(720, 930), 150, win);
        display_text(get_position(700, 50), "SPEEDLIST", 100, win);
        display_all_boss_cars(game, win);
    }
}
