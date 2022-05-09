/*
** EPITECH PROJECT, 2022
** my_RPG
** File description:
** init
*/

#include "rpg.h"

static void init_general_variables(game_t *game)
{
    game->dealership_buttons[2].texture = sfTexture_createFromFile(
    "files/buttons/purchase.png", NULL);
    game->dealership_buttons[2].sprite = get_sprite(
    game->dealership_buttons[2].texture);
    sfSprite_setTextureRect(game->dealership_buttons[2].sprite,
    get_rect(0, 0, 200, 80));
    sfSprite_setPosition(game->dealership_buttons[2].sprite,
    get_position(850, 900));
    sfSprite_setTextureRect(game->dealership_buttons[1].sprite,
    get_rect(0, 0, 324, 450));
    for (int i = 0; i < 3; ++i)
        game->dealership_buttons[i].is_pressed = 0;
    init_inventory(game);
    game->garage = malloc(1 * sizeof(car_t));
    game->garage->nb_cars = 1;
    create_garage_button(game->main_buttons);
    create_cars(game);
    init_return(game);
    init_rules(game);
    init_quests(game);
}

static void init_dealership_buttons(game_t *game)
{
    game->dealership_buttons = malloc(3 * sizeof(button_t));
    game->dealership_buttons->nb_buttons = 3;
    game->dealership_buttons[0].texture = sfTexture_createFromFile(
    "files/buttons/arrow.png", NULL);
    game->dealership_buttons[0].sprite = get_sprite(
    game->dealership_buttons[0].texture);
    sfSprite_setTextureRect(game->dealership_buttons[0].sprite,
    get_rect(0, 0, 324, 450));
    sfSprite_setScale(game->dealership_buttons[0].sprite,
    get_position(0.4, 0.4));
    sfSprite_setPosition(game->dealership_buttons[0].sprite,
    get_position(100, 500));
    game->dealership_buttons[1].texture = sfTexture_createFromFile(
    "files/buttons/arrow.png", NULL);
    game->dealership_buttons[1].sprite = get_sprite(
    game->dealership_buttons[1].texture);
    sfSprite_setScale(game->dealership_buttons[1].sprite,
    get_position(-0.4, 0.4));
    sfSprite_setPosition(game->dealership_buttons[1].sprite,
    get_position(1830, 500));
}

void rpg_init(game_t *game)
{
    game->main_buttons = malloc(15 * sizeof(button_t));
    game->backgrounds = malloc(14 * sizeof(background_t));
    game->colision_rect = malloc(sizeof(sfRectangleShape *) * 12);
    game->clock.clock = sfClock_create();
    game->speedrun_clock.clock = sfClock_create();
    init_sprite(game);
    game->scene = 0;
    game->music.music_index = 0;
    game->user.money = 100;
    game->main_buttons[0].rect = (sfIntRect){0, 0, 34, 13};
    game->inventory.rect = (sfIntRect){0, 0, 50, 48};
    game->backgrounds[10].texture = sfTexture_createFromFile
    ("files/misc/pause.png", NULL);
    game->backgrounds[10].sprite = get_sprite(game->backgrounds[10].texture);
    game->pause = 0;
    init_map(game);
    init_dealership_buttons(game);
    init_general_variables(game);
    init_xp(game);
}

void init_sprite(game_t *game)
{
    game->items = malloc(sizeof(item_t) * 91);
    game->nb_items = -1;
    game->inv_page = 1;
    game->backgrounds[0].texture = sfTexture_createFromFile
    ("files/background/bg.png", NULL);
    game->backgrounds[0].sprite = get_sprite(game->backgrounds[0].texture);
    sfSprite_setScale(game->backgrounds[0].sprite, get_position(1, 1));
    sfSprite_setPosition(game->backgrounds[0].sprite, get_position(0, 0));
    init_button_start(game);
    init_button_quit(game); init_race(game);
    game->backgrounds[6].texture = sfTexture_createFromFile
    ("files/background/bg_end.png", NULL);
    game->backgrounds[6].sprite = get_sprite(game->backgrounds[6].texture);
    sfSprite_setScale(game->backgrounds[6].sprite, get_position(2.7, 2.7));
    sfSprite_setPosition(game->backgrounds[6].sprite, get_position(0, 0));
    game->backgrounds[1].texture = sfTexture_createFromFile
    ("files/background/bg.png", NULL);
    game->backgrounds[1].sprite = get_sprite(game->backgrounds[1].texture);
    init_logo(game); game->money = 200000;
    init_pause(game); init_more_backgrounds(game);
}
