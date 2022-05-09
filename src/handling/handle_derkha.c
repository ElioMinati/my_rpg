/*
** EPITECH PROJECT, 2022
** my_RPG
** File description:
** handle_derkha
*/

#include "rpg.h"

void init_pnj(game_t *game)
{
    game->pnj = malloc(sizeof(pnj_t) * 1);
    game->pnj[0].texture = sfTexture_createFromFile
    ("files/misc/leandre.png", NULL);
    game->pnj[0].sprite = get_sprite(game->pnj[0].texture);
    sfSprite_setScale(game->pnj[0].sprite, get_position(0.7, 0.7));
    sfSprite_setPosition(game->pnj[0].sprite, get_position(1800, -1800));
    sfSprite_setTexture(game->pnj[0].sprite,
    game->pnj[0].texture, sfTrue);
}

void manage_answer(game_t *game)
{
    if (sfKeyboard_isKeyPressed(sfKeyY)) {
        game->current_quest = 5;
        game->leandre = 0;
    }
    if (sfKeyboard_isKeyPressed(sfKeyN))
        game->leandre = 0;
}

void handle_leandre(sfRenderWindow *win, game_t *game)
{
    sfVector2f pos = sfSprite_getPosition(game->backgrounds[3].sprite);

    if (pos.y > -100 && pos.x < -1650 && pos.x > -1800) {
        display_text(get_position(570, 800), "Press E to talk to Leandre",
        50, win);
        if (sfKeyboard_isKeyPressed(sfKeyE))
            game->leandre = 1;
    }
    if (game->leandre == 1) {
        draw_rect(get_position(800, 650), get_position(1120, 500), 150, win);
        display_text(get_position(950, 650),
        "Do you want to reset your quest ?", 50, win);
        display_text(get_position(1140, 730), "Yes", 50, win);
        display_text(get_position(1480, 730), "No", 50, win);
        manage_answer(game);
    }
}