/*
** EPITECH PROJECT, 2022
** my_RPG
** File description:
** reward
*/

#include "rpg.h"
#include "my.h"

void display_rewards(game_t *game, sfRenderWindow *win)
{
    display_text(get_position(1120, 545), game->reward, 45, win);
    display_text(get_position(1120, 475), my_itoa(game->get_xp), 45, win);
}

void get_reward_win(game_t *game)
{
    game->reward = NULL;
    int gold = 0;
    int xp = my_atoi(game->xp);
    game->get_xp = 0;

    gold += 500 + (rand() % game->current_car.horse_power);
    game->reward = malloc(sizeof(char) * 100);
    game->xp = malloc(sizeof(char) * 100);
    game->reward = my_itoa(gold);
    game->money += gold;
    xp += 250;
    game->get_xp = 250;
    game->xp = my_itoa(xp);
}

void get_reward_lose(game_t *game)
{
    game->reward = NULL;
    int gold = 0;
    int xp = my_atoi(game->xp);
    game->get_xp = 0;

    gold += (rand() % game->current_car.horse_power);
    game->reward = malloc(sizeof(char) * 100);
    game->xp = malloc(sizeof(char) * 100);
    game->reward = my_itoa(gold);
    game->money += gold;
    xp += 100;
    game->get_xp = 100;
    game->xp = my_itoa(xp);
}
