/*
** EPITECH PROJECT, 2022
** my_RPG
** File description:
** quest
*/

#include "rpg.h"

void init_quests(game_t *game)
{
    game->quest = malloc(6 * sizeof(quest_t));
    game->quest[0].text = "Win against 10 enemies";
    game->quest[1].text = "Win against 20 enemies";
    game->quest[2].text = "Spend 1500$";
    game->quest[3].text = "Play matches 20 times";
    game->quest[4].text = "Buy a new car";
    game->races_win = 0;
    game->money_spend = 0;
    game->current_quest = 5;
    game->car_is_bought = 0;
    game->races_done = 0;
}

void choose_quest(sfRenderWindow *window, game_t *game)
{
    if (game->current_quest == 5) {
        game->current_quest = rand() % 5;
        game->races_win = 0; game->money_spend = 0;
        game->car_is_bought = 0; game->races_done = 0;
    }
    if ((game->current_quest == 0 && game->inventory.status != 1)
        && (game->current_quest == 0 && game->main_buttons[8].is_toggled != 1))
        display_quest_one(window, game);
    if ((game->current_quest == 1 && game->inventory.status != 1)
        && (game->current_quest == 1 && game->main_buttons[8].is_toggled != 1))
        display_quest_two(window, game);
    if ((game->current_quest == 2 && game->inventory.status != 1)
        && (game->current_quest == 2 && game->main_buttons[8].is_toggled != 1))
        display_quest_three(window, game);
    if ((game->current_quest == 3 && game->inventory.status != 1)
        && (game->current_quest == 3 && game->main_buttons[8].is_toggled != 1))
        display_quest_four(window, game);
    if ((game->current_quest == 4 && game->inventory.status != 1)
        && (game->current_quest == 4 && game->main_buttons[8].is_toggled != 1))
        display_quest_five(window, game);
}
