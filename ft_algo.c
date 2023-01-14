#include "header.h"

void afficher_pile(t_list **pile, char c);

/*void ft_principale(t_list **pile_a, t_list **pile_b, int ac)
{
	
}*/

void ft_algo(t_list **pile_a, /*t_list **pile_b,*/ int ac)
{
	t_list *premier;
	t_list *deuxieme;
	t_list *dernier;

	premier = *pile_a;
	deuxieme = premier->next;
	dernier = ft_lstlast(*pile_a);
	if(!ft_verif_ordre(pile_a, 'a'))
	{
		if (premier->nombre > deuxieme->nombre)
		{
			if(premier->nombre > dernier->nombre)
			{
				ft_ra_rb(pile_a, 'a');
				ft_algo(pile_a, ac);
			}
			else
			{
				ft_sa_sb(pile_a, 'a');
				ft_algo(pile_a, ac);
			}
		}
		else
		{
			if(premier->nombre > dernier->nombre)
			{
				ft_rra_rrb(pile_a, 'a');
				ft_algo(pile_a, ac);
			}
			else
			{
				ft_algo_2(pile_a);
				ft_algo(pile_a, ac);
			}
		}
	}
}

void ft_algo_2(t_list **pile_a/*, t_list **pile_b,*/)
{
	t_list *premier;
	t_list *deuxieme;
	t_list *dernier;

	premier = *pile_a;
	deuxieme = premier->next;
	dernier = ft_lstlast(*pile_a);
	if(!ft_verif_ordre(pile_a, 'a'))
	{
		if (deuxieme->nombre > dernier->nombre)
		{
			ft_sa_sb(pile_a, 'a');
			ft_ra_rb(pile_a, 'a');
		}
		else
		{
			ft_ra_rb(pile_a, 'a');
			ft_algo_2(pile_a);
		}
	}
}

int ft_medianne(t_list **pile_a, int ac)
{
	int max;
	int min;
	int medianne;
	t_list *actuel;

	actuel = *pile_a;
	medianne = 0;
	min = actuel->nombre;
	max = actuel->nombre;
	while(actuel)
	{
		if(min > actuel->nombre)
			min  = actuel->nombre;
		if(max < actuel->nombre)
			max = actuel->nombre;
		actuel = actuel->next;
	}
	medianne = ((max - min)/2) + min;
	if(medianne >= ft_moyenne(pile_a, ac))
		medianne = ((medianne - ft_moyenne(pile_a, ac))/2) + ft_moyenne(pile_a, ac);
	else
		medianne = ((ft_moyenne(pile_a, ac) - medianne)/2) + medianne;
	return (medianne);
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
			if(precedent->nombre > actuel->nombre)
				return (0);
			precedent = actuel;
			actuel = actuel->next;
		}
	}
	else if(c == 'b')
	{
		if(ft_lstsize(*pile) == 1)
			return 1;
		while(actuel)
		{
			if(precedent->nombre < actuel->nombre)
				return (0);
			precedent = actuel;
			actuel = actuel->next;
		}
	}
	return (1);
}