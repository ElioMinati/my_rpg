/*
** EPITECH PROJECT, 2022
** music.c
** File description:
** :
*/

#include "rpg.h"

void create_music(char *filename, music_t *music)
{
    music->music = sfMusic_createFromFile(filename);
    music->has_played = 1;
    sfMusic_setLoop(music->music, sfFalse);
    sfMusic_play(music->music);
}

void play_music(sfMusic *music)
{
    sfMusic_stop(music);
    sfMusic_play(music);
}
