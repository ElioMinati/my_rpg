/*
** EPITECH PROJECT, 2022
** my_RPG
** File description:
** rules_scene
*/

#include "rpg.h"

void manage_info_button(sfRenderWindow *window, game_t *game)
{
    if (is_button_pressed(game, game->main_buttons[3])) {
        game->scene = 7;
    }
}

void manage_rules_return(sfRenderWindow *window, game_t *game)
{
    if (game->event.type == sfEvtMouseButtonPressed){
        if (game->event.mouseButton.x > 1815 &&
        game->event.mouseButton.y > 15 &&
        game->event.mouseButton.x < 1910 &&
        game->event.mouseButton.y < 80) {
            game->scene = 0;
            game->event.type = sfEvtMouseButtonReleased;
        }
    }
}

void display_rules(sfRenderWindow *window, game_t *game)
{
    display_window(window);
    sfRenderWindow_drawSprite(window, game->backgrounds[0].sprite, NULL);
    sfRenderWindow_drawSprite(window, game->main_buttons[10].sprite, NULL);
    display_text(get_position(250, 250), game->rules, 50, window);
    manage_rules_return(window, game);
}
