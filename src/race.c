/*
** EPITECH PROJECT, 2022
** my_RPG
** File description:
** race
*/

#include "rpg.h"

void set_enemy_car(game_t *game, car_t car)
{
    game->enemy_car.max_speed = game->current_car.max_speed / 1.2 + rand() % 20;
    game->enemy_car.horse_power =
    game->current_car.horse_power / 1.15 + rand() % 20;
    game->enemy_car.texture = sfSprite_getTexture(car.sprite);
    game->enemy_car.sprite = get_sprite(game->enemy_car.texture);
    game->enemy_car.anim = sfClock_create();
    game->enemy_car.rect_offset = car.rect_offset;
    game->enemy_car.rect_max = car.rect_max;
    sfSprite_setPosition(game->enemy_car.sprite, get_position(960, 590));
    sfSprite_setOrigin(game->enemy_car.sprite, car.offset);
    sfSprite_setTextureRect(game->enemy_car.sprite,
    sfSprite_getTextureRect(car.sprite));
    sfSprite_setScale(game->enemy_car.sprite, get_position(0.7, 0.7));
}

void get_random_enemy(game_t *game, car_t *cars)
{
    int randint = rand() % 4;
    int index = -1;

    for (int i = 0; i < cars->nb_cars; ++i) {
        if (game->current_car.price == cars[i].price)
            index = i;
    }
    if (randint == 2)
        randint = 3;
    if (randint > 2 && index == (cars->nb_cars - 1))
        randint = 1;
    randint += index - 2;
    if (randint < 0)
        randint = 0;
    set_enemy_car(game, cars[randint]);
}

void move_parallax(game_t *game, sfRenderWindow *win)
{
    sfVector2f bg_pos = sfSprite_getPosition(game->parallax[0].sprite);

    game->race.race_clock.seconds = sfTime_asSeconds(
    sfClock_getElapsedTime(game->race.race_clock.clock)) - 3;
    game->race.gear_clock.seconds = sfTime_asSeconds(
    sfClock_getElapsedTime(game->race.gear_clock.clock));
    game->race.current_vel = -5 * game->current_car.horse_power *
    (game->race.time_since_max_rev + game->race.gear_clock.seconds) * 0.01;
    game->race.enemy_vel = -5 * game->enemy_car.horse_power *
    game->race.race_clock.seconds * 0.01;
    game->race.pitch += (game->race.current_vel >
    (-game->current_car.max_speed / game->current_car.max_gear) *
    game->current_car.gear) ? game->race.pitch_incr *
    game->current_car.horse_power : 0;
    if (game->race.gear_clock.seconds < 1 && game->race.race_clock.seconds > 4)
        display_particles(win, game);
    if (game->race.current_vel < (-game->current_car.max_speed /
    game->current_car.max_gear) * game->current_car.gear)
        do_gear_up(game, win);
    move_race_objects(game, bg_pos);
}

static int handle_pause_ig(sfRenderWindow *window, game_t *game)
{
    sfRenderWindow_drawSprite(window, game->main_buttons[14].sprite, NULL);
    if (game->pause == 0 && is_button_pressed(game, game->main_buttons[14])) {
        game->pause = 1;
        sfSprite_setTextureRect(game->main_buttons[14].sprite,
        get_rect(28, 0, 28, 28));
    } else if (is_button_hovered(window, game, game->main_buttons[14]))
        sfSprite_setTextureRect(game->main_buttons[14].sprite,
        get_rect(28, 0, 28, 28));
    else
        sfSprite_setTextureRect(game->main_buttons[14].sprite,
        get_rect(28, 0, 28, 28));
    if (game->pause == 1)
        analyse_pause_events(game, window);
    display_pause_menu(window, game);
    if (game->pause == 1)
        return 1;
    return 0;
}

void display_race(sfRenderWindow *window, game_t *game)
{
    display_window(window);
    choose_time(window, game);
    sfRenderWindow_drawSprite(window, game->parallax[0].sprite, NULL);
    sfRenderWindow_drawSprite(window, game->enemy_car.sprite, NULL);
    sfRenderWindow_drawSprite(window, game->current_car.sprite, NULL);
    if (handle_pause_ig(window, game))
        return;
    if (game->race.race_has_started == 1) {
        move_parallax(game, window);
    } else {
        if (game->race.boss != -1 && game->race.anim != 1) {
            handle_boss_anim(window, game);
            return;
        }
        handle_race_start(game, window);
    }
    if (game->race.race_has_started == 1 && (sfTime_asSeconds(
    sfClock_getElapsedTime(game->race.race_clock.clock)) < 4))
        display_start_countdown(0, window);
    handle_during_race(game, window);
}
