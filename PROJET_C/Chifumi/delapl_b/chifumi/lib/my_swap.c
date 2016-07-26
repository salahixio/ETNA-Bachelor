/*
** my_swap.c for ok in /home/antoine/Jour03-C/delapl_b/my_swap
** 
** Made by DELAPLACE Antoine
** Login   <delapl_b@etna-alternance.net>
** 
** Started on  Wed Oct 21 10:22:50 2015 DELAPLACE Antoine
** Last update Wed Oct 21 10:32:13 2015 DELAPLACE Antoine
*/

void	my_swap(int *a, int *b)
{
  int	tmp;

  tmp = *a;
  *a = *b;
  *b = tmp;
}
