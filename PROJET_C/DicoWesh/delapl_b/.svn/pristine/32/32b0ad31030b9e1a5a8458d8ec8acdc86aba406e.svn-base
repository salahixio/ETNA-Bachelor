/*
** play_sound_for_word.c for ok in /home/antoine/Documents/TEST_SOUND
**
** Made by DELAPLACE Antoine
** Login   <delapl_b@etna-alternance.net>
**
** Started on  Fri Nov  6 19:01:55 2015 DELAPLACE Antoine
** Last update Sat Nov  7 13:04:46 2015 DELAPLACE Antoine
*/

#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>

void		play_sound_for_word(char *name)
{
  Mix_Music	*musique;

  SDL_Init(SDL_INIT_VIDEO);
  SDL_WM_SetCaption("SDL_Mixer", NULL);
  if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT,
		    MIX_DEFAULT_CHANNELS, 1024) == -1)
    {
      printf("%s", Mix_GetError());
    }
  musique = Mix_LoadMUS(name);
  Mix_PlayMusic(musique, 1);
  while (Mix_PlayingMusic())
    {
    }
  Mix_FreeMusic(musique);
  Mix_CloseAudio();
  SDL_Quit();
}
