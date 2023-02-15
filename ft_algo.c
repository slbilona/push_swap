#include "header.h"

/*
ft_tri_pile_a
ft_algo
ft_algo_2
ft_verif_ordre
*/

void	ft_algo(t_list **pile_a)
{
	t_list	*premier;
	t_list	*deuxieme;
	t_list	*dernier;

	premier = *pile_a;
	deuxieme = premier->next;
	dernier = ft_lstlast(*pile_a);
	if (!ft_verif_ordre(pile_a, 'a'))
	{
		if (premier->nombre > deuxieme->nombre)
		{
			if (premier->nombre > dernier->nombre)
				ft_ra_rb(pile_a, 'a');
			else
				ft_sa_sb(pile_a, 'a');
		}
		else
		{
			if (premier->nombre > dernier->nombre)
				ft_rra_rrb(pile_a, 'a');
			else
				ft_sa_sb(pile_a, 'a');
		}
		ft_algo(pile_a);
	}
}

//ENLEVE LE CHAR C
int	ft_verif_ordre(t_list **pile, char c)
{
	t_list	*actuel;
	t_list	*precedent;

	actuel = *pile;
	precedent = actuel;
	actuel = actuel->next;
	if (c == 'a')
	{
		while (actuel)
		{
			if (precedent->nombre > actuel->nombre)
				return (0);
			precedent = actuel;
			actuel = actuel->next;
		}
	}
	return (1);
}
