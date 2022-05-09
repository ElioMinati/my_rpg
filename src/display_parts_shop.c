/*
** EPITECH PROJECT, 2022
** display_parts_shop.c
** File description:
** display parts shop
*/

#include "rpg.h"

void draw_selected(sfRenderWindow *win, game_t *game)
{
    sfIntRect rect;
    sfVector2f scale;
    sfVector2f origin;
    sfVector2f pos;

    if (game->parts->selected != -1) {
        rect = sfSprite_getTextureRect(
        game->parts[game->parts->selected].sprite);
        scale = sfSprite_getScale(
        game->parts[game->parts->selected].sprite);
        origin = sfSprite_getOrigin(game->parts[game->parts->selected].sprite);
        pos = sfSprite_getPosition(game->parts[game->parts->selected].sprite);
        draw_green_border_rect(get_position(pos.x - origin.x *
        scale.x, pos.y - origin.y * scale.y),
        get_position(rect.width * scale.x, rect.height * scale.y), 0, win);
        sfRenderWindow_drawSprite(win,
        game->dealership_buttons[2].sprite, NULL);
    }
}

static void select_turbo_part(sfRenderWindow *win, game_t *game)
{
    for (int i = 0; i < 4; ++i) {
        sfRenderWindow_drawSprite(win, game->parts[i].sprite, NULL);
        if (is_button_pressed(game, game->parts[i])) {
            sfSprite_setPosition(game->dealership_buttons[2].sprite,
            get_position(100, 900));
            game->parts->selected = i;
        }
    }
    draw_selected(win, game);
}

static void display_turbo(sfRenderWindow *win, game_t *game)
{
    if (game->parts[4].is_toggled == 1) {
        draw_rect(get_position(50, 700), get_position(1820, 300), 200, win);
        select_turbo_part(win, game);
        display_text(get_position(405, 730), "Small Turbo", 30, win);
        display_text(get_position(560, 800), "$ 650", 20, win);
        display_text(get_position(560, 830), "PSI: 4", 20, win);
        display_text(get_position(415, 930), "Power gain: x1.2", 20, win);
        display_text(get_position(715, 730), "Regular Turbo", 30, win);
        display_text(get_position(890, 800), "$ 1240", 20, win);
        display_text(get_position(890, 830), "PSI: 7", 20, win);
        display_text(get_position(725, 930), "Power gain: x1.5", 20, win);
        display_text(get_position(1035, 730), "Bi-Turbo", 30, win);
        display_text(get_position(1190, 800), "$ 7680", 20, win);
        display_text(get_position(1190, 830), "PSI: 17", 20, win);
        display_text(get_position(1040, 930), "Power gain: x2", 20, win);
        display_text(get_position(1305, 730), "Diamond Turbo", 30, win);
        display_text(get_position(1490, 800), "$ 18799", 20, win);
        display_text(get_position(1490, 830), "PSI: 32", 20, win);
        display_text(get_position(1335, 930), "Power gain: x2.8", 20, win);
    }
}

void display_part_shop(sfRenderWindow *window, game_t *game)
{
    display_window(window);
    sfRenderWindow_drawSprite(window, game->backgrounds[8].sprite, NULL);
    sfRenderWindow_drawSprite(window, game->parts[4].sprite, NULL);
    sfRenderWindow_drawSprite(window, game->parts[5].sprite, NULL);
    sfRenderWindow_drawSprite(window, game->parts[10].sprite, NULL);
    sfRenderWindow_drawSprite(window, game->parts[16].sprite, NULL);
    sfRenderWindow_drawSprite(window, game->parts[20].sprite, NULL);
    sfRenderWindow_drawSprite(window, game->main_buttons[10].sprite, NULL);
    display_turbo(window, game);
    display_air_filters(window, game);
    display_radiators(window, game);
    display_pistons(window, game);
    display_money(window, game);
    display_cartos(window, game);
    analyse_shop_events(window, game);
    display_xp(game, window);
    manage_return(window, game);
}
