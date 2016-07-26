/*
** my_put_revstr.c for ok in /home/antoine/Jour03-C/delapl_b/my_put_revstr
** 
** Made by DELAPLACE Antoine
** Login   <delapl_b@etna-alternance.net>
** 
** Started on  Wed Oct 21 10:49:32 2015 DELAPLACE Antoine
** Last update Wed Oct 21 18:30:41 2015 DELAPLACE Antoine
*/

int	my_strlen(char *str);
void	my_putchar(char c);
void	my_putstr(char *str);

void	my_put_revstr(char *str)
{
  int	i;
  int	j;
  char	tmp;

  i = 0;
  j = my_strlen(str) - 1;
  while (i < j)
    {
      tmp = *(str + i);
      *(str + i) = *(str + j);
      *(str + j) = tmp;
      i = i + 1;
      j = j - 1;
    }
  my_putstr(str);
}

int	my_strlen(char *str)
{
  int   i;

  i = 0;
  while (*(str + i) != '\0')
    {
      ++i;
    }
  return (i);
}

void	my_putstr(char *str)
{
  int   i;

  i = 0;
  while (*(str + i) != '\0')
    {
      my_putchar(*(str + i));
      ++i;
    }
}
