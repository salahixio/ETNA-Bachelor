/*
** readLine.c for ok in /home/antoine/Colle1/delapl_b/step_one
** 
** Made by DELAPLACE Antoine
** Login   <delapl_b@etna-alternance.net>
** 
** Started on  Fri Oct 23 09:23:28 2015 DELAPLACE Antoine
** Last update Sat Oct 24 00:42:20 2015 DELAPLACE Antoine
*/

#include<stdlib.h>
#include<unistd.h>

char		*readLine()
{
  ssize_t	ret;
  char		*buff;
	
  if ((buff = malloc(sizeof(*buff) * (50 + 1))) == NULL)
    return (NULL);
  if ((ret = read(0, buff, 50)) > 1)
    {
      buff[ret - 1] = '\0';
      return (buff);
    }
  buff[0] = '\0';
  return (buff);
}
