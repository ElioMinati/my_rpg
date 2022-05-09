/*
** EPITECH PROJECT, 2022
** display_xp
** File description:
** functions used to display experience
*/

#include "rpg.h"
#include "my.h"

void handle_xp(game_t *game)
{
    game->get_xp = my_atoi(game->xp);
    if (game->get_xp > (500 + 700 * game->level))
        game->level += 1;
}

void display_xp(game_t *game, sfRenderWindow *win)
{
    sfRenderWindow_drawSprite(win,
    game->main_buttons[12].sprite, NULL);
    handle_xp(game);
    display_text(get_position(290, 2), my_itoa(game->level), 20, win);
    display_text(get_position(360, -4), game->xp, 30, win);
}
