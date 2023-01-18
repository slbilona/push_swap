#include "header.h"

void	afficher_pile(t_list **pile, char c);

void	ft_tri_pile_a(t_list **pile_a, t_list **pile_b, int ac)
{
	t_list	*premier_a;
	int		i;

	i = 0;
	//printf("\nmilieu : %d\n", ((ac)/2));
	while (i < (ac - 1))
	{
		premier_a = *pile_a;
		// if(premier_a->place == (ac - 2) || premier_a->place == (ac - 3) || premier_a->place == (ac - 4))
		// {
		// 	ft_ra_rb(pile_a, 'a');
		// }
		if (premier_a->place >= (ac / 2))
			ft_ra_rb(pile_a, 'a');
		else if (premier_a->place < (ac / 2)
			&& premier_a->place >= ((ac / 2) / 2))
		{
			ft_pa_pb(pile_a, pile_b, 'b');
		}
		else
		{
			ft_pa_pb(pile_a, pile_b, 'b');
			ft_ra_rb(pile_b, 'b');
		}
		i++;
	}
}

void	ft_algo(t_list **pile_a/*, t_list **pile_b, int ac*/)
{
	t_list	*premier;
	t_list	*deuxieme;
	t_list	*dernier;
	//t_list *av_dernier;

	premier = *pile_a;
	deuxieme = premier->next;
	dernier = ft_lstlast(*pile_a);
	//av_dernier = ft_almostlast(*pile_a);
	//afficher_pile(pile_a, 'a');
	if (!ft_verif_ordre(pile_a, 'a'))
	{
		if (premier->nombre > deuxieme->nombre)
		{
			if (premier->nombre > dernier->nombre)
			{
				//printf("1\n");
				ft_ra_rb(pile_a, 'a');
				ft_algo(pile_a);
			}
			else
			{
				//printf("2\n");
				ft_sa_sb(pile_a, 'a');
				ft_algo(pile_a);
			}
		}
		else
		{
			if (premier->nombre > dernier->nombre)
			{
				//printf("3\n");
				ft_ra_rb(pile_a, 'a');
				ft_algo(pile_a);
			}
			else
			{
				if (deuxieme->nombre > dernier->nombre)
				{
					ft_sa_sb(pile_a, 'a');
					ft_algo(pile_a);
				}
				else
				{
					//printf("4\n");
					ft_algo_2(pile_a);
					ft_algo(pile_a);
				}
			}
		}
	}
}

void	ft_algo_2(t_list **pile_a/*, t_list **pile_b,*/)
{
	t_list	*premier;
	t_list	*deuxieme;
	t_list	*dernier;
	t_list	*av_dernier;

	premier = *pile_a;
	deuxieme = premier->next;
	dernier = ft_lstlast(*pile_a);
	av_dernier = ft_almostlast(*pile_a);
	//afficher_pile(pile_a, 'a');
	if (!ft_verif_ordre(pile_a, 'a'))
	{
		if (deuxieme->nombre > dernier->nombre)
		{
			printf("5\n");
			ft_sa_sb(pile_a, 'a');
			//ft_ra_rb(pile_a, 'a');
		}
		else
		{
			//printf("6\n");
			if (av_dernier->nombre < dernier->nombre &&
				av_dernier->nombre < premier->nombre)
			{
				ft_rra_rrb(pile_a, 'a');
				ft_rra_rrb(pile_a, 'a');
				ft_algo_2(pile_a);
			}
			else
			{
				ft_ra_rb(pile_a, 'a');
				ft_algo_2(pile_a);
			}
		}
	}
}

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
	else if (c == 'b')
	{
		if (ft_lstsize(*pile) == 1)
			return (1);
		while (actuel)
		{
			if (precedent->nombre < actuel->nombre)
				return (0);
			precedent = actuel;
			actuel = actuel->next;
		}
	}
	return (1);
}
