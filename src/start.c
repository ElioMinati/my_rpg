/*
** EPITECH PROJECT, 2022
** my_RPG
** File description:
** start
*/

#include "rpg.h"

void display_start(sfRenderWindow *window, game_t *game)
{
    display_window(window);
    sfRenderWindow_drawSprite(window, game->backgrounds[0].sprite, NULL);
    sfRenderWindow_drawSprite(window, game->main_buttons[2].sprite, NULL);
    sfRenderWindow_drawSprite(window, game->main_buttons[0].sprite, NULL);
    sfRenderWindow_drawSprite(window, game->backgrounds[7].sprite, NULL);
    sfRenderWindow_drawSprite(window, game->main_buttons[1].sprite, NULL);
    sfRenderWindow_drawSprite(window, game->main_buttons[3].sprite, NULL);
    manage_start_button(window, game);
    manage_quit_button(window, game);
    manage_end_button(window, game);
    manage_info_button(window, game);
}