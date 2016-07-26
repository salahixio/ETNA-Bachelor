/*
** palindrome_rec.c for palindrome in /home/antoine/ALGO/Jour01/delapl_b/palindrome_rec
**
** Made by DELAPLACE Antoine
** Login   <delapl_b@etna-alternance.net>
**
** Started on  Mon Nov  2 10:56:08 2015 DELAPLACE Antoine
** Last update Mon Nov  2 15:27:11 2015 DELAPLACE Antoine
*/

int	palindrome_rec(char *str, int debut, int fin)
{
  int	palindrome;

  palindrome = 1;
  while (str[debut] == ' ')
    ++debut;
  while (str[fin] == ' ')
    fin = fin - 1;
  if (str[debut] != str[fin])
    return (0);
  else if (debut < fin)
    palindrome = palindrome_rec(str, debut + 1, fin - 1);
  return (palindrome);
}
