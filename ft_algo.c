#include "header.h"

void afficher_pile(t_list **pile, char c);
void ft_b_dans_a(t_list **pile_a, t_list **pile_b);

void ft_algo(t_list **pile_a, t_list **pile_b, int ac)
{
	int moyenne;
	t_list *actuel;
	int i;
	//t_list *dernier;

	i = 0;
	actuel = *pile_a;
	moyenne = ft_moyenne(pile_a, ac);
	//printf("\n%d\n", moyenne);
	while(!ft_verif_ordre(pile_a, 'a'))
	{
		afficher_pile(pile_a, 'a');
		afficher_pile(pile_b, 'b');
		if(actuel->nombre < moyenne)
		{
			//printf("pa = %d\n", actuel->nombre);
			ft_pa_pb(pile_a, pile_b, 'b');
			actuel = *pile_a;
		}
		else
		{
			ft_ra_rb(pile_a, 'a');
			actuel = *pile_a;
		}
		if(ft_verif_ordre(pile_a, 'a') && ft_verif_ordre(pile_b, 'b'))
		{
			ft_b_dans_a(pile_a, pile_b);
		}
		i++;
	}
}

void ft_b_dans_a(t_list **pile_a, t_list **pile_b)
{
	int i;

	i = 0;
	while(*pile_b)
	{
		ft_pa_pb(pile_a, pile_a, 'a');
		i++;
	}
}
int ft_moyenne(t_list **pile_a, int ac)
{
	int moyenne;
	t_list *actuel;

	actuel = *pile_a;
	moyenne = 0;
	while (actuel)
	{
		moyenne += actuel->nombre;
		actuel = actuel->next;
	}
	moyenne = moyenne / (ac - 1);
	return (moyenne);
}

int ft_verif_ordre(t_list **pile, char c)
{
	t_list *actuel;
	t_list *precedent;

	actuel = *pile;
	precedent = actuel;
	actuel = actuel->next;
	if(c == 'a')
	{
		while(actuel)
		{
			if(precedent->nombre < actuel->nombre)
				return (0);
			precedent = actuel;
			actuel = actuel->next;
		}
	}
	else if(c == 'b')
	{
		while(actuel)
		{
			if(precedent->nombre > actuel->nombre)
				return (0);
			precedent = actuel;
			actuel = actuel->next;
		}
	}
	return (1);
}