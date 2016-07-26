/*
** fill_tab.c for  in /home/antoine/C/Chifumi/delapl_b/chifumi
**
** Made by DELAPLACE Antoine
** Login   <delapl_b@etna-alternance.net>
**
** Started on  Fri Oct 30 03:03:05 2015 DELAPLACE Antoine
** Last update Fri Oct 30 05:36:29 2015 DELAPLACE Antoine
*/

void	fill_tab(int mode, char **choices)
{
  choices[0] = "quitter";
  choices[1] = "pierre";
  choices[2] = "feuille";
  choices[3] = "ciseaux";
  if (mode == 5)
    {
      choices[4] = "lezard";
      choices[5] = "spock";
    }
}
