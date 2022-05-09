/*
** EPITECH PROJECT, 2022
** analyse_events2
** File description:
** .
*/

#include "rpg.h"

void detect_car_pressed(game_t *game, sfVector2i mouse)
{
    if (mouse.x > 100 && mouse.y > 530 && mouse.x < 500 && mouse.y < 700)
        sfSprite_setScale(game->cars[0].sprite, get_position(1.1, 1.1));
    else
        sfSprite_setScale(game->cars[0].sprite, get_position(1, 1));
    if (mouse.x > 700 && mouse.y > 538 && mouse.x < 1130 && mouse.y < 700)
        sfSprite_setScale(game->cars[1].sprite, get_position(1.1, 1.1));
    else
        sfSprite_setScale(game->cars[1].sprite, get_position(1, 1));
    if (mouse.x > 1320 && mouse.y > 530 && mouse.x < 1810 && mouse.y < 700)
        sfSprite_setScale(game->cars[2].sprite, get_position(1.1, 1.1));
    else
        sfSprite_setScale(game->cars[2].sprite, get_position(1, 1));
}

static void analyse_second_arrow_press(game_t *game)
{
    sfVector2f spos = {0, 0};

    if (is_button_pressed(game, game->main_buttons[6]) &&
    sfSprite_getPosition(game->garage[game->garage->nb_cars - 1].sprite).x
    > 1900) {
        sfSprite_setTextureRect(game->main_buttons[6].sprite,
        get_rect(450, 0, 324, 450));
        game->garage->selected = -1;
        for (int i = 0; i < game->garage->nb_cars; ++i) {
            spos = sfSprite_getPosition(game->garage[i].sprite);
            spos.x -= 550;
            sfSprite_setPosition(game->garage[i].sprite, spos);
        }
    } else {
        sfSprite_setTextureRect(game->main_buttons[6].sprite,
        get_rect(0, 0, 324, 450));
    }
}

static void analyse_arrow_pressing(game_t *game)
{
    sfVector2f spos = {0, 0};

    if (is_button_pressed(game, game->main_buttons[5]) &&
    sfSprite_getPosition(game->garage[0].sprite).x < 300) {
        sfSprite_setTextureRect(game->main_buttons[5].sprite,
        get_rect(450, 0, 324, 450));
        game->garage->selected = -1;
        for (int i = 0; i < game->garage->nb_cars; ++i) {
            spos = sfSprite_getPosition(game->garage[i].sprite);
            spos.x += 550;
            sfSprite_setPosition(game->garage[i].sprite, spos);
        }
    } else {
        sfSprite_setTextureRect(game->main_buttons[5].sprite,
        get_rect(0, 0, 324, 450));
    }
    analyse_second_arrow_press(game);
}

void move_garage_cars(game_t *game)
{
    sfVector2f pos = {400, 600};

    if (game->main_buttons[4].is_toggled == 0) {
        game->main_buttons[4].is_toggled = 1;
        game->garage->selected = -1;
        for (int i = 0; i < game->garage->nb_cars; ++i) {
            sfSprite_setPosition(game->garage[i].sprite, pos);
            sfSprite_setScale(game->garage[i].sprite,
            get_position(0.8, 0.8));
            pos.x += 550;
        }
    } else {
        game->main_buttons[4].is_toggled = 0;
        sfSprite_setTextureRect(game->main_buttons[4].sprite,
        get_rect(284, 0, 178, 142));
    }
}

void analyse_garage_events(game_t *game, sfVector2i mouse, sfRenderWindow *win)
{
    sfVector2f pos = {400, 600};

    analyse_equip_events(game, win);
    analyse_unequip_events(game, win);
    analyse_item_pressing(game, win);
    detect_garage_button(win, game);
    if (game->main_buttons[4].is_toggled == 1) {
        display_text(get_position(500, 250), "Choose your car:", 100, win);
        draw_rect(get_position(150, 400), get_position(1600, 300), 200, win);
        display_garage_cars(game->garage, win);
        sfRenderWindow_drawSprite(win, game->main_buttons[5].sprite, NULL);
        sfRenderWindow_drawSprite(win, game->main_buttons[6].sprite, NULL);
        analyse_arrow_pressing(game);
        detect_garage_car_pressing(game);
    }
    manage_return(win, game);
}
