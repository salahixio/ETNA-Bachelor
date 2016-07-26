/*
** my_next_char.c for next_char in /home/delapl_b/Jour01-C/delapl_b/my_next_char
** 
** Made by DELAPLACE Antoine
** Login   <delapl_b@etna-alternance.net>
** 
** Started on  Mon Oct 19 13:31:50 2015 DELAPLACE Antoine
** Last update Mon Oct 19 14:18:54 2015 DELAPLACE Antoine
*/

char	my_next_char(char c)
{
  char	next_char;

  if (c == 'z')
    {
      next_char = 'a';
    }
  else if (c == 'Z')
    {
      next_char = 'A';
    }
  else if (c < 65 || c > 122 || (c > 90 && c < 97))
    {
      next_char = ' ';
    }
  else
    {
      next_char = c + 1;
    }
  return (next_char);
}
