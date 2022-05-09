/*
** EPITECH PROJECT, 2022
** do_race.c
** File description:
** functions that are made to do the race
*/

#include "rpg.h"

static void handle_loss(game_t *game, sfRenderWindow *window)
{
    if (game->race.race_has_started == 1) {
        sfClock_destroy(game->race.gear_clock.clock);
        get_reward_win(game);
        game->current_car.horse_power = game->race.init_hp;
        game->races_win += 1;
        game->races_done += 1;
        if (game->race.boss != -1)
            game->speedlist[game->race.boss].eliminated = 1;
    }
    game->race.pitch -= (game->race.pitch > 1) ? 0.02 : 0;
    game->race.race_has_started = 0;
    display_end_menu(1, game->race.score, window, game);
    display_rewards(game, window);
}

void handle_during_race(game_t *game, sfRenderWindow *window)
{
    if (game->race.distance >= 1000 &&
    sfSprite_getPosition(game->current_car.sprite).x >
    sfSprite_getPosition(game->enemy_car.sprite).x) {
        handle_loss(game, window);
    } else if (game->race.enemy_distance >= 1000 &&
    sfSprite_getPosition(game->current_car.sprite).x <=
    sfSprite_getPosition(game->enemy_car.sprite).x) {
        if (game->race.race_has_started == 1) {
            sfClock_destroy(game->race.gear_clock.clock);
            get_reward_lose(game);
            game->current_car.horse_power = game->race.init_hp;
            game->races_done += 1;
        }
        game->race.race_has_started = 0;
        game->race.pitch -= (game->race.pitch > 1) ? 0.02 : 0;
        display_end_menu(0, game->race.score, window, game);
        display_rewards(game, window);
    }
    sfMusic_setPitch(game->music.music, game->race.pitch);
}

void move_race_objects(game_t *game, sfVector2f bg_pos)
{
    if (game->race.enemy_vel < -game->enemy_car.max_speed)
        game->race.enemy_vel = -game->enemy_car.max_speed;
    move_texture_rect(game->current_car.sprite, game->current_car.rect_offset,
    game->current_car.rect_max, game->current_car.anim);
    move_texture_rect(game->enemy_car.sprite, game->enemy_car.rect_offset,
    game->enemy_car.rect_max, game->enemy_car.anim);
    if (bg_pos.x <= -((768 / 3) * 8)) {
        sfSprite_setPosition(game->parallax[0].sprite,
        get_position(0, 600 - 20));
    } else {
        game->race.distance -= game->race.current_vel / 100;
        game->race.enemy_distance -= game->race.enemy_vel / 100;
        sfSprite_move(game->parallax[0].sprite,
        get_position(game->race.current_vel, 0));
        sfSprite_move(game->enemy_car.sprite,
        get_position(game->race.current_vel - game->race.enemy_vel, 0));
    }
}

void do_gear_up(game_t *game, sfRenderWindow *win)
{
    game->race.current_vel = (-game->current_car.max_speed
    / game->current_car.max_gear) * game->current_car.gear;
    if (game->race.is_max_rev == 0)
        game->race.time_since_max_rev += game->race.gear_clock.seconds;
    game->race.is_max_rev = 1;
    display_gear_up(game, win);
    if (sfKeyboard_isKeyPressed(game->key)) {
        game->key = rand() % 25;
        ++game->current_car.gear;
        game->race.gear_up_speed = game->race.current_vel;
        game->race.is_max_rev = 0;
        game->current_car.horse_power += 4;
        game->race.pitch = 2 + game->current_car.gear;
        game->race.pitch_incr -= 0.000015;
        if (game->race.stutu.has_played == 0 && game->current_car.turbo != 0)
            create_music("files/music/stu.ogg", &game->race.stutu);
        else if (game->current_car.turbo != 0)
            play_music(game->race.stutu.music);
        sfClock_restart(game->race.gear_clock.clock);
    }
}
