/*
** EPITECH PROJECT, 2022
** my_RPG
** File description:
** display_quests
*/

#include "rpg.h"
#include "my.h"

void display_quest_one(sfRenderWindow *window, game_t *game)
{
    char *progress = NULL;

    progress = malloc(sizeof(char) * 100);
    progress = my_strcat(my_itoa(game->races_win), " / 10");
    draw_rect(get_position(700, 0), get_position(520, 150), 125, window);
    display_text(get_position(880, 0), "QUEST", 50, window);
    display_text(get_position(720, 50),
        game->quest[game->current_quest].text, 40, window);
    display_text(get_position(890, 100), progress, 40, window);
    free(progress);
    if (game->races_win == 10) {
        game->money += 1000;
        game->races_win = 0;
        game->current_quest = 5;
    }
}

void display_quest_two(sfRenderWindow *window, game_t *game)
{
    char *progress = NULL;

    progress = malloc(sizeof(char) * 100);
    progress = my_strcat(my_itoa(game->races_win), " / 20");
    draw_rect(get_position(700, 0), get_position(520, 150), 125, window);
    display_text(get_position(880, 0), "QUEST", 50, window);
    display_text(get_position(710, 50),
        game->quest[game->current_quest].text, 40, window);
    display_text(get_position(890, 100), progress, 40, window);
    free(progress);
    if (game->races_win == 20) {
        game->money += 5000;
        game->races_win = 0;
        game->current_quest = 5;
    }
}

void display_quest_three(sfRenderWindow *window, game_t *game)
{
    char *progress = NULL;

    progress = malloc(sizeof(char) * 100);
    progress = my_strcat(my_itoa(game->money_spend), " / 1500");
    draw_rect(get_position(700, 0), get_position(520, 150), 125, window);
    display_text(get_position(880, 0), "QUEST", 50, window);
    display_text(get_position(840, 50),
        game->quest[game->current_quest].text, 40, window);
    display_text(get_position(880, 100), progress, 40, window);
    free(progress);
    if (game->money_spend >= 1500) {
        game->money += 750;
        game->money_spend = 0;
        game->current_quest = 5;
    }
}

void display_quest_four(sfRenderWindow *window, game_t *game)
{
    char *progress = NULL;

    progress = malloc(sizeof(char) * 100);
    progress = my_strcat(my_itoa(game->races_done), " / 20");
    draw_rect(get_position(700, 0), get_position(520, 150), 125, window);
    display_text(get_position(880, 0), "QUEST", 50, window);
    display_text(get_position(720, 50),
        game->quest[game->current_quest].text, 40, window);
    display_text(get_position(890, 100), progress, 40, window);
    free(progress);
    if (game->races_done == 20) {
        game->money += 3000;
        game->races_done = 0;
        game->current_quest = 5;
    }
}

void display_quest_five(sfRenderWindow *window, game_t *game)
{
    char *progress = NULL;

    progress = malloc(sizeof(char) * 100);
    progress = my_strcat(my_itoa(game->car_is_bought), " / 1");
    draw_rect(get_position(700, 0), get_position(520, 150), 125, window);
    display_text(get_position(880, 0), "QUEST", 50, window);
    display_text(get_position(820, 50),
        game->quest[game->current_quest].text, 40, window);
    display_text(get_position(890, 100), progress, 40, window);
    free(progress);
    if (game->car_is_bought == 1) {
        game->money += 1000;
        game->car_is_bought = 0;
        game->current_quest = 5;
    }
}
