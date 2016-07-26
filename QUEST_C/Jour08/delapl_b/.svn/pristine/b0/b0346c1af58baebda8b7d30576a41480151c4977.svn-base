/*
** my_params_to_tab.c for ok in /home/antoine/C/Jour08-C/delapl_b/my_params_to_tab
** 
** Made by DELAPLACE Antoine
** Login   <delapl_b@etna-alternance.net>
** 
** Started on  Tue Oct 27 10:18:58 2015 DELAPLACE Antoine
** Last update Tue Oct 27 17:50:34 2015 DELAPLACE Antoine
*/

#include<stdlib.h>

struct	s_stock_par
{
  int	size_param;
  char	*str;
  char	*copy;
  char	**tab;
};

char	**my_str_to_wordtab(char *str);
char	*my_strdup(char *str);
int	my_strlen(char *str);

struct s_stock_par	*my_params_to_tab(int ac, char **av)
{
  struct s_stock_par	*params;
  int			i;
  
  i = 0;
  params = malloc(sizeof(*params) * (ac + 1));
  while (i < ac)
    {
      if (my_strlen(av[i]) != 0)
	{
	  params[i].size_param = my_strlen(av[i]);
	  params[i].str = av[i];
	  params[i].copy = my_strdup(av[i]);
	  params[i].tab = my_str_to_wordtab(av[i]);
	}
      ++i;
    }
  params[i].str = NULL;
  return (params);
}
