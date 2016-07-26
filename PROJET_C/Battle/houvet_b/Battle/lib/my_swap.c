/*
** my_swap.c for my_swap in /home/houvet_b/libmy
** 
** Made by HOUVET Benoît - Xavier
** Login   <houvet_b@etna-alternance.net>
** 
** Started on  Sat Oct 24 14:59:58 2015 HOUVET Benoît - Xavier
** Last update Sat Oct 24 16:44:44 2015 HOUVET Benoît - Xavier
*/

void	my_swap(int *a, int *b)
{
  int	temp;

  temp = *a;
  *a = *b;
  *b = temp;
}
