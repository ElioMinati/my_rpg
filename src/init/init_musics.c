/*
** EPITECH PROJECT, 2022
** init_musics.c
** File description:
** initialize musics used in rpg
*/

#include "rpg.h"
#include "my.h"

void init_musics(game_t *game)
{
    game->songs = malloc(8 * sizeof(char *));
    game->songs[0] = my_strdup("files/music/titouan.ogg");
    game->songs[1] = my_strdup("files/music/pierrick.ogg");
    game->songs[2] = my_strdup("files/music/eliott.ogg");
    game->songs[3] = my_strdup("files/music/adrian.ogg");
    game->songs[4] = my_strdup("files/music/skeler1.ogg");
    game->songs[5] = my_strdup("files/music/skeler2.ogg");
    game->songs[6] = my_strdup("files/music/skeler3.ogg");
    game->songs[7] = my_strdup("files/music/skeler4.ogg");
}
