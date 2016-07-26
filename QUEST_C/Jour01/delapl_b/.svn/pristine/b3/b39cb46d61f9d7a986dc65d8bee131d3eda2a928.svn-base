/*
** my_prev_char.c for prev_char in /home/delapl_b/Jour01-C/delapl_b/my_prev_char
** 
** Made by DELAPLACE Antoine
** Login   <delapl_b@etna-alternance.net>
** 
** Started on  Mon Oct 19 13:31:50 2015 DELAPLACE Antoine
** Last update Mon Oct 19 15:53:38 2015 DELAPLACE Antoine
*/

char	my_prev_char(char c)
{
  char	prev_char;

  if (c == 'a')
    {
      prev_char = 'z';
    }
  else if (c == 'A')
    {
      prev_char = 'Z';
    }
  else if (c < 65 || c > 122 || (c > 90 && c < 97))
    {
      prev_char = ' ';
    }
  else
    {
      prev_char = c - 1;
    }
  return (prev_char);
}
