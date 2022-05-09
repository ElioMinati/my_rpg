/*
** EPITECH PROJECT, 2022
** my_RPG
** File description:
** sound
*/

#include "rpg.h"

void music_endgame(sfRenderWindow *window, game_t *game, char *path)
{
    sfMusic_stop(game->music.music);
    sfMusic_destroy(game->music.music);
    game->music.music = sfMusic_createFromFile(path);
    sfMusic_play(game->music.music);
    sfMusic_setLoop(game->music.music, sfTrue);
    game->music.music_index = 1;
}

void music_ingame(sfRenderWindow *window, game_t *game, char *path)
{
    if (game->scene == 5 && game->music.music_index == 0) {
        sfMusic_stop(game->music.music);
        sfMusic_destroy(game->music.music);
        game->music.music = sfMusic_createFromFile(path);
        sfMusic_play(game->music.music);
        sfMusic_setPitch(game->music.music, 1);
        sfMusic_setLoop(game->music.music, sfTrue);
        game->music.music_index = 1;
    }
}

void music_game(sfRenderWindow *window, game_t *game, char *path)
{
    if (game->scene == 2 && game->music.music_index == 1) {
        sfMusic_stop(game->music.music);
        sfMusic_destroy(game->music.music);
        game->music.music = sfMusic_createFromFile(path);
        sfMusic_play(game->music.music);
        sfMusic_setLoop(game->music.music, sfTrue);
        game->music.music_index = 0;
    }
}

void music(sfRenderWindow *window, game_t *game)
{
    music_ingame(window, game, "files/music/vroom.ogg");
    music_game(window, game, "files/music/game_theme.ogg");
}

void music_menu(game_t *game)
{
    game->music.music = sfMusic_createFromFile("files/music/game_theme.ogg");
    sfMusic_setLoop(game->music.music, sfTrue);
    sfMusic_play(game->music.music);
}
