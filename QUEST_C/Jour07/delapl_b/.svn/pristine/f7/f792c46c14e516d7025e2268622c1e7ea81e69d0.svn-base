/*
** my_sort_params_ascii_len.c for ok in /home/antoine/C/Jour07-C/delapl_b/my_sort_params_ascii_len
** 
** Made by DELAPLACE Antoine
** Login   <delapl_b@etna-alternance.net>
** 
** Started on  Mon Oct 26 16:06:56 2015 DELAPLACE Antoine
** Last update Mon Oct 26 18:02:46 2015 DELAPLACE Antoine
*/

int	my_strlen(char *str);
void	my_aff_params(int argc, char **argv);
void	my_putchar(char c);
void	my_putstr(char *str);
void	change_min(int i, int indice_min, char *min, char **argv);
int	my_strcmp(char *s1, char *s2);

void	my_sort_params_ascii_len(int argc, char **argv)
{
  int	i;
  int	j;
  char*	min;
  int	indice_min;

  i = 0;
  while (i < argc - 1)
    {
      min = argv[i];
      indice_min = i;
      j = i + 1;
      while (j < argc)
	{
	  if ((my_strlen(min) < my_strlen(argv[j])) ||
	      (my_strlen(min) == my_strlen(argv[j]) && my_strcmp(min, argv[j]) > 0))
	    {
	      min = argv[j];
	      indice_min = j;
	    }
	  j++;
	}
      change_min(i, indice_min, min, argv);
      i++;
    }
  my_aff_params(argc, argv);
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

void	change_min(int i, int indice_min, char *min, char **argv)
{
  if (i != indice_min)
    {
      argv[indice_min] = argv[i];
      argv[i] = min;
    }
}
