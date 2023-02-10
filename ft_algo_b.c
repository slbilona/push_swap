#include "header.h"
/*
ft_algo_b
ft_algo_2_b
ft_b_dans_a
*/
void	afficher_pile(t_list **pile, char c);

void	ft_algo_b(t_list **pile_b)
{
	t_list	*premier;
	t_list	*deuxieme;
	t_list	*dernier;

	premier = *pile_b;
	deuxieme = premier->next;
	dernier = ft_lstlast(*pile_b);
	if (!ft_verif_ordre(pile_b, 'b'))
	{
		if (premier->nombre < deuxieme->nombre)
		{
			if (premier->nombre < dernier->nombre)
			{
				ft_ra_rb(pile_b, 'b');
				ft_algo_b(pile_b);
			}
			else
			{
				ft_sa_sb(pile_b, 'b');
				ft_algo_b(pile_b);
			}
		}
		else
		{
			if (premier->nombre < dernier->nombre)
			{
				ft_ra_rb(pile_b, 'b');
				ft_algo_b(pile_b);
			}
			else
			{
				if (deuxieme->nombre < dernier->nombre)
				{
					ft_sa_sb(pile_b, 'b');
					ft_algo_b(pile_b);
				}
				else
				{
					ft_algo_2_b(pile_b);
					ft_algo_b(pile_b);
				}
			}
		}
	}
}

void	ft_algo_2_b(t_list **pile_b)
{
	t_list	*premier;
	t_list	*deuxieme;
	t_list	*dernier;
	t_list	*av_dernier;

	premier = *pile_b;
	deuxieme = premier->next;
	dernier = ft_lstlast(*pile_b);
	av_dernier = ft_almostlast(*pile_b);
	if (!ft_verif_ordre(pile_b, 'b'))
	{
		if (deuxieme->nombre < dernier->nombre)
			ft_sa_sb(pile_b, 'b');
		else
		{
			if (av_dernier->nombre > dernier->nombre
				&& av_dernier->nombre > premier->nombre)
			{
				ft_rra_rrb(pile_b, 'b');
				ft_rra_rrb(pile_b, 'b');
				ft_algo_2_b(pile_b);
			}
			else
			{
				ft_ra_rb(pile_b, 'b');
				ft_algo_2_b(pile_b);
			}
		}
	}
}

void	ft_b_dans_a(t_list **pile_a, t_list **pile_b)
{
	while (*pile_b)
	{
		ft_pa_pb(pile_b, pile_a, 'a');
	}
}
