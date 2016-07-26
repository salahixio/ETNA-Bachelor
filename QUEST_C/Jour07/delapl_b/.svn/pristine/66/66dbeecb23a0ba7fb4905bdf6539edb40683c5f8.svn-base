/*
** my_str_to_wordtab.c for ok in /home/antoine/C/Jour07-C/delapl_b/my_str_to_wordtab
** 
** Made by DELAPLACE Antoine
** Login   <delapl_b@etna-alternance.net>
** 
** Started on  Mon Oct 26 11:19:48 2015 DELAPLACE Antoine
** Last update Tue Oct 27 13:08:25 2015 DELAPLACE Antoine
*/

#include<stdlib.h>

int	check_alpha_numerique(char *str, int pos_char);
int	count_words(char *str);
void	fill_tab(char **tab, char *str);
char	*my_strdup(char *str);

char	**my_str_to_wordtab(char *str)
{
  char	**tab;
  char	*new_str;

  new_str = my_strdup(str);
  tab = malloc(sizeof(char *) * (count_words(str) + 1));
  fill_tab(tab, new_str);
  return (tab);
}

int	check_alpha_numerique(char *str, int pos_char)
{
  if (*(str + pos_char) > 47 && *(str + pos_char) < 58)
    return (1);
  else if (*(str + pos_char) > 64 && *(str + pos_char) < 91)
    return (1);
  else if (*(str + pos_char) > 96 && *(str + pos_char) < 123)
    return (1);
  else
    return (0);
}

int	count_words(char *str)
{
  int	find_word;
  int	count_words;
  int	i;

  i = 0;
  find_word = 0;
  count_words = 0;
  while (*(str + i) != '\0')
    {
      if (check_alpha_numerique(str, i) && !find_word)
	{
	  find_word = 1;
	  ++count_words;
	}
      else if (!check_alpha_numerique(str, i))
	find_word = 0;
      ++i;
    }
  return (count_words);
}

void	fill_tab(char **tab, char *str)
{
  int	i;
  int	find_word;
  int	pos_tab;

  i = 0;
  find_word = 0;
  pos_tab = 0;  
  while (*(str + i) != '\0')
    {
      if (!check_alpha_numerique(str, i))
	{
	  find_word = 0;
	  *(str + i) = '\0';
	}
      else if (check_alpha_numerique(str, i) && !find_word)
	{
	  find_word = 1;
	  tab[pos_tab] = malloc(sizeof(char *));
	  tab[pos_tab] = str + i;
	  ++pos_tab;
	}
      ++i;
    }
  tab[pos_tab] = "\0";
}
