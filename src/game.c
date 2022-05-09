/*
** EPITECH PROJECT, 2022
** my_RPG
** File description:
** game
*/

#include "rpg.h"
#include "my.h"

void display_garage(sfRenderWindow *window, game_t *game)
{
    display_window(window);
    sfRenderWindow_drawSprite(window, game->backgrounds[4].sprite, NULL);
    sfSprite_setRotation(game->current_car.sprite, 0);
    sfSprite_setPosition(game->current_car.sprite, get_position(900, 750));
    sfSprite_setScale(game->current_car.sprite, get_position(1.7, 1.7));
    sfRenderWindow_drawSprite(window, game->current_car.sprite, NULL);
    sfRenderWindow_drawSprite(window, game->main_buttons[4].sprite, NULL);
    sfRenderWindow_drawSprite(window, game->main_buttons[10].sprite, NULL);
    display_money(window, game);
    inv_event(window, game);
    sfRenderWindow_drawSprite(window, game->inventory.button_sprite, NULL);
    if (game->inventory.status == 1)
        display_inventory(window, game);
}

void display_player_stats(sfRenderWindow *window, game_t *game)
{
    display_text(get_position(475, 185), "PLAYER STATS", 50, window);
    display_text(get_position(450, 250), "XP:", 40, window);
    display_text(get_position(525, 250), game->xp, 40, window);
    display_text(get_position(450, 290), "MONEY:", 40, window);
    display_text(get_position(625, 290), my_itoa(game->money), 40, window);
    display_text(get_position(505, 410), "ITEM STATS", 50, window);
}

static void display_backgrounds(sfRenderWindow *window, game_t *game)
{
    sfRenderWindow_drawSprite(window, game->backgrounds[3].sprite, NULL);
    sfRenderWindow_drawSprite(window, game->pnj[0].sprite, NULL);
    sfRenderWindow_drawSprite(window, game->current_car.sprite, NULL);
    sfRenderWindow_drawSprite(window, game->backgrounds[9].sprite, NULL);
    sfRenderWindow_drawSprite(window, game->inventory.button_sprite, NULL);
    sfRenderWindow_drawSprite(window, game->main_buttons[8].sprite, NULL);
}

void display_pause_menu(sfRenderWindow *window, game_t *game)
{
    if (sfKeyboard_isKeyPressed(sfKeyEscape))
        game->pause = 1;
    if (game->pause == 1) {
        draw_rect(get_position(0, 0), get_position(1920, 1080), 120, game->win);
        sfRenderWindow_drawSprite(window, game->backgrounds[10].sprite, NULL);
        sfRenderWindow_drawSprite(window, game->main_buttons[13].sprite, NULL);
        manage_quit_button(window, game);
        sfRenderWindow_drawSprite(window, game->main_buttons[2].sprite, NULL);
    }
}

void display_game(sfRenderWindow *window, game_t *game)
{
    display_window(window);
    if (game->current_car.is_moving == 1 && game->pause == 0) {
        move_texture_rect(game->current_car.sprite,
        game->current_car.rect_offset,
        game->current_car.rect_max, game->current_car.anim);
        game->current_car.is_moving = 0;
    }
    inv_event(window, game);
    display_backgrounds(window, game);
    if (game->inventory.status == 1 && game->pause == 0)
        display_inventory(window, game);
    display_money(window, game);
    display_xp(game, window);
    choose_quest(window, game);
    display_pause_menu(window, game);
}
