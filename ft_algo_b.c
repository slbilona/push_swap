#include "header.h"

void	afficher_pile(t_list **pile, char c);

void	ft_algo_b(t_list **pile_b)
{
	t_list	*premier;
	t_list	*deuxieme;
	t_list	*dernier;
	//t_list *av_dernier;

	premier = *pile_b;
	deuxieme = premier->next;
	dernier = ft_lstlast(*pile_b);
	//av_dernier = ft_almostlast(*pile_b);
	//afficher_pile(pile_b, 'a');
	if (!ft_verif_ordre(pile_b, 'b'))
	{
		if (premier->nombre < deuxieme->nombre)
		{
			if (premier->nombre < dernier->nombre)
			{
				//printf("1\n");
				ft_ra_rb(pile_b, 'b');
				ft_algo_b(pile_b);
			}
			else
			{
				//printf("2\n");
				ft_sa_sb(pile_b, 'b');
				ft_algo_b(pile_b);
			}
		}
		else
		{
			if (premier->nombre < dernier->nombre)
			{
				//printf("3\n");
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
					//printf("4\n");
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
	//afficher_pile(pile_b, 'a');
	if (!ft_verif_ordre(pile_b, 'b'))
	{
		if (deuxieme->nombre < dernier->nombre)
		{
			//printf("5\n");
			ft_sa_sb(pile_b, 'b');
			//ft_ra_rb(pile_b, 'a');
		}
		else
		{
			//printf("6\n");
			if (av_dernier->nombre > dernier->nombre &&
				av_dernier->nombre > premier->nombre)
			{
				ft_rra_rrb(pile_b, 'b');
				ft_rra_rrb(pile_b, 'b');
				ft_algo_2_b(pile_b);
			}
			else
			{
				//printf("6\n");
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