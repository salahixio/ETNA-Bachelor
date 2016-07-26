/*
** my_detect_format.c for ok in /home/antoine/Jour03-C/delapl_b/my_detect_format
** 
** Made by DELAPLACE Antoine
** Login   <delapl_b@etna-alternance.net>
** 
** Started on  Wed Oct 21 12:58:28 2015 DELAPLACE Antoine
** Last update Wed Oct 21 14:30:44 2015 DELAPLACE Antoine
*/

void    my_putchar(char c);
void	my_putword(char *str);
void    my_affiche_format(char *str, int depart, int type);

void	my_detect_format(char *str)
{
  int	i;
  int	depart;
  int	type;

  i = 0;
  depart = 0;
  type = 0;
  while (*(str + i) != '\0')
    {
      if (*(str + i) > 47 && *(str + i) < 58 && (type == 0 || type == 1)) 
	type = 1;
      else if (((*(str + i) > 64 && *(str + i) < 91) ||
		(*(str + i) > 96 && *(str + i) < 123)) && (type == 0 || type == 2))
	type = 2;
      else if (*(str + i) == 32)
	{
	  my_affiche_format(str, depart, type);
	  type = 0;
	  depart = i + 1;
	}
      else
	type = 3;
      ++i;
    }
  my_affiche_format(str, depart, type);
}

void	my_putword(char *str)
{
  int	i;

  i = 0;
  while (*(str + i) != '\0' && *(str + i) != ' ')
    {
      my_putchar(*(str + i));
      ++i;
    }
}

void	my_affiche_format(char *str, int depart, int type)
{
  my_putword(str + depart);
  my_putchar(' ');
  my_putchar('=');
  my_putchar('>');
  my_putchar(' ');
  if (type == 1)
    my_putword("Chiffre\n");
  else if (type == 2)
    my_putword("Mot\n");
  else
    my_putword("Inconnu\n");
}
