/*
** my_sum_params.c for ok in /home/antoine/C/Jour07-C/delapl_b/my_sum_params
** 
** Made by DELAPLACE Antoine
** Login   <delapl_b@etna-alternance.net>
** 
** Started on  Mon Oct 26 15:23:40 2015 DELAPLACE Antoine
** Last update Mon Oct 26 16:42:45 2015 DELAPLACE Antoine
*/

#include<stdlib.h>

int	count_chars(int argc, char **argv);

char	*my_sum_params(int argc, char **argv)
{
  char	*str;
  int	i;
  int	j;
  int	k;
  
  str = malloc(sizeof(char) * count_chars(argc, argv));
  i = 0;
  k = 0;
  while (i < argc)
    {
      j = 0;
      while (argv[i][j] != '\0')
	{
	  str[k] = argv[i][j];
	  k++;
	  j++;
	}
      if ((i + 1) != argc)
	str[k]= '\n';
      k++;
      i++;      
    }
  return (str);
}

int     count_chars(int argc, char **argv)
{
  int   count_chars;
  int   i;
  int	j;
  
  i = 0;
  count_chars = 0;
  while (i < argc)
    {
      j = 0;
      while (argv[i][j] != '\0')
	{
	  count_chars++;
	  ++j;
	}
	++i;
	count_chars++;
    }
  return (count_chars);
}
