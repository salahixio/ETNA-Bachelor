/*
** dec_cesar.c for  in /home/antoine/ALGO/Jour02
**
** Made by DELAPLACE Antoine
** Login   <delapl_b@etna-alternance.net>
**
** Started on  Tue Nov  3 09:27:49 2015 DELAPLACE Antoine
** Last update Tue Nov  3 14:59:31 2015 DELAPLACE Antoine
*/

void	my_putchar(char c);
void	encrypte(char *str, int n);

void	dec_cesar(char *str, int n)
{
  int	i;
  char	c;

  if (n < 0)
    encrypte(str, (-n));
  else
    {
      while (*str != '\0')
	{
	  i = 1;
	  c = *str;
	  while (i <= n)
	    {
	      if (c == 'a')
		c = 'z';
	      else if (c == 'A')
		c = 'Z';
	      else if ((c > 'a' && c <= 'z') || (c > 'A' && c <= 'Z'))
		c = c - 1;
	      ++i;
	    }
	  my_putchar(c);
	  str = str + 1;
	}
    }
}

void    encrypte(char *str, int n)
{
  int   i;
  char  c;

  while (*str != '\0')
    {
      i = 1;
      c = *str;
      while (i <= n)
	{
	  if (c == 'z')
	    c = 'a';
	  else if (c == 'Z')
	    c = 'A';
	  else if ((c >= 'a' && c < 'z') || (c >= 'A' && c < 'Z'))
	    c = c + 1;
	  ++i;
	}
      my_putchar(c);
      str = str + 1;
    }
}
