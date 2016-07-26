/*
** main.c for  in /home/antoine/C/Jour08-C/delapl_b/do-op
** 
** Made by DELAPLACE Antoine
** Login   <delapl_b@etna-alternance.net>
** 
** Started on  Tue Oct 27 14:06:14 2015 DELAPLACE Antoine
** Last update Tue Oct 27 17:56:14 2015 DELAPLACE Antoine
*/

void		my_putstr(char *str);
int		my_getnbr(char *str);
void		my_put_nbr(int nbr);
int		addition(int a, int b);
int		soustraction(int a, int b);
int		multiplication(int a, int b);
int		division(int a, int b);
int		modulo(int a, int b);
void		my_putchar(char c);

typedef		int (*operation) (int, int);

char		check_operande(char *str)
{
  char		c;

  c = '\0';
  if ((*str == '/' || *str ==  '%' || *str == '+' || *str == '-'
      || *str == '*') && *(str + 1) == '\0')
    c = *str;
  else if (*str == '\'' && *(str + 1) == '*')
    c = '*';
  return (c);
}

int		check_entry(int argc, char **argv)
{
  int		check;

  check = 0;
  if (argc > 4)
    {
      check = 1;
      my_putstr("Syntax Error");
    }
  else if ((!my_getnbr(argv[1]) && argv[1][0] != '0')
	  || (!my_getnbr(argv[3]) && argv[3][0] != '0')
	  || check_operande(argv[2]) == '\0')
    {
      check = 1;
      my_putstr("Syntax Error");
    }
  else if (argv[3][0] == '0' && (check_operande(argv[2]) == '%'
				  || check_operande(argv[2]) == '/'))
    {
      check = 1;
      my_putstr("Va t'acheter des doigts");
    }
  return (check);
}

int		do_op(int argc, char **argv)
{
  operation	fct_op[5];
  char		op[5];
  int		i;

  i = 0;
  fct_op[0] = &addition;
  fct_op[1] = &soustraction;
  fct_op[2] = &multiplication;
  fct_op[3] = &division;
  fct_op[4] = &modulo;
  op[0] = '+';
  op[1] = '-';
  op[2] = '*';
  op[3] = '/';
  op[4] = '%';
  if (check_entry(argc, argv))
    return (0);
  else
    while (i < 5)
      {
	if (op[i] == check_operande(argv[2]))
	  my_put_nbr(fct_op[i](my_getnbr(argv[1]), my_getnbr(argv[3])));
	++i;
      }   
  return (1);
}

int		main(int argc, char **argv)
{
  if (argc > 3)
    {
      do_op(argc, argv);
      my_putstr("\n");
    }
  return (0);
}
