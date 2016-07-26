/*
** fonctions_lib.h for star in /Users/benoit-xavierhouvet/Desktop/ETNA/PROJ_C/houvet_b
**
** Made by HOUVET Benoît - Xavier
** Login   <houvet_b@etna-alternance.net>
**
** Started on  Mon Dec 14 18:08:10 2015 HOUVET Benoît - Xavier
** Last update Mon Dec 14 18:32:27 2015 HOUVET Benoît - Xavier
*/

#ifndef FONCTIONS_LIB_H_
# define FONCTIONS_LIB_H_

void	my_putchar(char c);
int	my_isneg(int n);
void	my_put_nbr(int nb);
void	my_swap(int *a, int *b);
void	my_putstr(char *str);
int	my_strlen(char *str);
int	my_getnbr(char *str);
char	*my_strcpy(char *dest, char *src);
char	*my_strncpy(char *dest, char *src, int n);
int	my_strcmp(char *s1, char *s2);
int	my_strncmp(char *s1, char *s2, int n);
char	*my_strcat(char *str1, char *str2);
char	*my_strncat(char *str1, char *str2, int n);
char	*my_strstr(char *str, char *to_find);
char	*my_strdup(char *str);
char	**my_str_to_wordtab(char *str);
char	*readLine();

#endif /* !FONCTIONS_LIB_H_ */
