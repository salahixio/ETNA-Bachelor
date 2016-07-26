/*
** my_sort_params.c for ok in /home/antoine/Jour04-C/delapl_b/my_sort_params
** 
** Made by DELAPLACE Antoine
** Login   <delapl_b@etna-alternance.net>
** 
** Started on  Thu Oct 22 00:16:26 2015 DELAPLACE Antoine
** Last update Thu Oct 22 06:52:24 2015 DELAPLACE Antoine
*/

void	my_putchar(char c);

void	my_putstr(char *str)
{
  int	i;

  i = 0;
  while (*(str + i) != '\0')
    {
      my_putchar(*(str + i));
      ++i;
    }
}

void	my_aff_params(int nbr, char **arg)
{
  int	i;

  for (i = 0; i < nbr; i = i + 1)
    {
      my_putstr(*(arg + i));
      my_putchar('\n');
    }
}

int	my_strcmp(char *s1, char *s2)
{
  int	i;
  int	compare;

  i = 0;
  compare = 0;
  while (*(s1 + i) != '\0' && compare == 0)
    {
      if (*(s1 + i) > *(s2 + i))
	compare = 1;
      else if (*(s2 + i) > *(s1 + i))
	compare = (-1);
      ++i;
    }
  if (compare == 0)
    {
      if (*(s1 + i) > *(s2 + i))
	compare = 1;
      else if (*(s2 + i) > *(s1 + i))
	compare = -1;
    }
  return (compare);
}

void	my_sort_params(int nb, char **arg)
{
  int	i;
  int	j;
  char	*min;
  int	indice_min;

  i = 0;
  while(i < nb - 1)
    {
      min = arg[i];
      indice_min = i;
      j = i + 1;
      while(j < nb)
	{
	  if(my_strcmp(min, arg[j]) > 0)
	    {
	      min = arg[j];
	      indice_min = j; 
	    }
	  j++;
	}
      if(i != indice_min)
	{
	  arg[indice_min] = arg[i];
	  arg[i] = min;
	}
      i++;
    }
    my_aff_params(nb, arg);
}
