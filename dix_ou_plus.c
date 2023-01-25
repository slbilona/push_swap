#include "header.h"

void	afficher_pile(t_list **pile, char c);

void	ft_principale(t_list **pile_a, t_list **pile_b, int ac)
{
	// afficher_pile(pile_a, 'a');
	// afficher_pile(pile_b, 'b');
	ft_que_3(pile_a, pile_b, ac);
	ft_algo(pile_a);
	ft_je_sais_pas_ptn(pile_a, pile_b, ac);
}

int ft_compare_calculs(t_list **pile_a, t_list **pile_b, int ac)
{
	// t_list *premier;
	// t_list *deuxieme;
	int un;
	// int deux;
	int trois;

	// premier = *pile_b;
	// deuxieme = premier->next;
	un = ft_calcul(pile_a, *pile_b, ac);
	// deux = (ft_calcul(pile_a, deuxieme, ac) + 1);
	trois = (ft_calcul(pile_a, ft_lstlast(*pile_b), ac) + 1);
	// printf("un: %d, deux : %d, trois : %d\n", un, deux, trois);
	if (/*un <= deux && */un <= trois)
	{
		printf("1\n");
		return (1);
	}
	// else if (deux <= un && deux <= trois)
	// {
	// 	printf("2\n");
	// 	return (2);
	// }
	else if (trois <= un /*&& trois <= deux*/)
	{
		printf("hey 3\n");
		return (3);
	}
	// else
	// {

	// 	printf("1\n");
	// 	return ();
	// }
	return (0);
}

void ft_je_sais_pas_ptn(t_list **pile_a, t_list **pile_b, int ac)
{
	t_list *premier;
	t_list *deuxieme_b;
	int un;
	int deux;
	int trois;
	
	premier = *pile_a;
	if(ft_lstsize(*pile_a) != (ac-1))
	{
		deuxieme_b = *pile_b;
		deuxieme_b = deuxieme_b->next;
		un = ft_calcul(pile_a, *pile_b, ac);
		deux = ft_calcul(pile_a, deuxieme_b, ac) + 1;
		trois = ft_calcul(pile_a, ft_lstlast(*pile_b), ac) + 1;
		// printf("taille pile a : %d\n", ft_lstsize(*pile_a));
		// printf("calcul 1 : %d\n", ft_calcul(pile_a, *pile_b, ac));
		// printf("calcul 2 : %d\n", (ft_calcul(pile_a, ft_lstlast(*pile_b), ac) + 1));
		if (un <= trois && un <= deux)
		{
			printf("1\n");
			if ((ft_lstsize(*pile_a)/2) <= ft_duo(pile_a, *pile_b, ac))
				ft_trier_bas(pile_a, pile_b, (ft_calcul(pile_a, *pile_b, ac) - 1));
			else
				ft_trier_haut(pile_a, pile_b, ft_calcul(pile_a, *pile_b, ac) - 1);
		}
		else if (trois <= un && trois <= deux)
		{
			printf("3\n");
			if ((ft_lstsize(*pile_a)/2) <= ft_duo(pile_a, ft_lstlast(*pile_b), ac))
			{
				ft_rrr(pile_a, pile_b);
				ft_trier_bas(pile_a, pile_b, (ft_calcul(pile_a, *pile_b, ac) - 2));
			}
			else
			{
				ft_rra_rrb(pile_b, 'b');
				ft_trier_haut(pile_a, pile_b, ft_calcul(pile_a, *pile_b, ac) - 1);
			}
		}
		else
		{
			printf("2\n");
			if ((ft_lstsize(*pile_a)/2) <= ft_duo(pile_a, deuxieme_b, ac))
			{
				ft_sa_sb(pile_b, 'b');
				ft_trier_bas(pile_a, pile_b, (ft_calcul(pile_a, *pile_b, ac) - 2));
			}
			else
			{
				ft_sa_sb(pile_b, 'b');
				ft_trier_haut(pile_a, pile_b, ft_calcul(pile_a, *pile_b, ac) - 1);
			}
		}
		ft_position(pile_a);
		ft_je_sais_pas_ptn(pile_a, pile_b, ac);
	}
	else if (premier->place != 0)
	{
		ft_rra_rrb(pile_a, 'a');
		ft_je_sais_pas_ptn(pile_a, pile_b, ac);
	}
}

// void ft_je_sais_pas_ptn(t_list **pile_a, t_list **pile_b, int ac)
// {
// 	t_list *premier;
	
// 	premier = *pile_a;
// 	if(ft_lstsize(*pile_a) != (ac-1))
// 	{
// 		// printf("taille pile a : %d\n", ft_lstsize(*pile_a));
// 		// printf("calcul 1 : %d\n", ft_calcul(pile_a, *pile_b, ac));
// 		// printf("calcul 2 : %d\n", (ft_calcul(pile_a, ft_lstlast(*pile_b), ac) + 1));
// 		if (ft_calcul(pile_a, *pile_b, ac) == (ft_calcul(pile_a, ft_lstlast(*pile_b), ac) + 1))
// 		{
// 			//printf("1\n");
// 			if ((ft_lstsize(*pile_a)/2) <= ft_duo(pile_a, *pile_b, ac))
// 				ft_trier_bas(pile_a, pile_b, (ft_calcul(pile_a, *pile_b, ac) - 1));
// 			else
// 				ft_trier_haut(pile_a, pile_b, ft_calcul(pile_a, *pile_b, ac) - 1);
// 		}
// 		else if (ft_calcul(pile_a, *pile_b, ac) > (ft_calcul(pile_a, ft_lstlast(*pile_b), ac) + 1))
// 		{
// 			//printf("2\n");
// 			if ((ft_lstsize(*pile_a)/2) <= ft_duo(pile_a, ft_lstlast(*pile_b), ac))
// 			{
// 				ft_rrr(pile_a, pile_b);
// 				ft_trier_bas(pile_a, pile_b, (ft_calcul(pile_a, *pile_b, ac) - 2));
// 			}
// 			else
// 			{
// 				ft_rra_rrb(pile_b, 'b');
// 				ft_trier_haut(pile_a, pile_b, ft_calcul(pile_a, *pile_b, ac) - 1);
// 			}
// 		}
// 		else if (ft_calcul(pile_a, *pile_b, ac) < (ft_calcul(pile_a, ft_lstlast(*pile_b), ac) + 1))
// 		{
// 			//printf("3\n");
// 			if ((ft_lstsize(*pile_a)/2) <= ft_duo(pile_a, *pile_b, ac))
// 				ft_trier_bas(pile_a, pile_b, (ft_calcul(pile_a, *pile_b, ac) - 1));
// 			else
// 				ft_trier_haut(pile_a, pile_b, ft_calcul(pile_a, *pile_b, ac) - 1);
// 		}
// 		ft_position(pile_a);
// 		ft_je_sais_pas_ptn(pile_a, pile_b, ac);
// 	}
// 	else if (premier->place != 0)
// 	{
// 		ft_rra_rrb(pile_a, 'a');
// 		ft_je_sais_pas_ptn(pile_a, pile_b, ac);
// 	}
// }

void	ft_trier_haut(t_list **pile_a, t_list **pile_b, int mouv)
{
	int	i;

	i = 0;
	while (i < mouv)
	{
		ft_ra_rb(pile_a, 'a');
		i++;
	}
	ft_pa_pb(pile_b, pile_a, 'a');
}

void	ft_trier_bas(t_list **pile_a, t_list **pile_b, int mouv)
{
	int	i;

	i = 0;
	while (i < mouv)
	{
		ft_rra_rrb(pile_a, 'a');
		i++;
	}
	ft_pa_pb(pile_b, pile_a, 'a');
}

void 	ft_que_3(t_list **pile_a, t_list **pile_b, int ac)
{
	t_list	*actuel;
	int		i;

	i = 0;
	while (i < (ac - 1))
	{
		actuel = *pile_a;
		if (actuel->place == (ac - 4) || actuel->place == (ac - 3) || actuel->place == (ac - 2))
			ft_ra_rb(pile_a, 'a');
		else if (actuel->place >= ((ac-4)/2))
			ft_pa_pb(pile_a, pile_b, 'b');
		else
		{
			ft_pa_pb(pile_a, pile_b, 'b');
			ft_ra_rb(pile_b, 'b');
		}
		i++;
	}
}

void	ft_position(t_list **pile)
{
	t_list	*actuel;
	int		i;

	i = 0;
	actuel = *pile;
	while (actuel)
	{
		actuel->position = i;
		actuel =actuel->next;
		i++;
	}
}

int	ft_calcul(t_list **pile, t_list *element, int ac)
{
	int	compte;

	compte = 0; 
	if ((ft_lstsize(*pile)/2) <= ft_duo(pile, element, ac))
		compte = (ft_lstsize(*pile)) - ft_duo(pile, element, ac);
	else
		compte = ft_duo(pile, element, ac);
	return (compte + 1);
	
}

int	ft_duo(t_list **pile_a, t_list *element, int ac)
{
	t_list	*actuel;
	int		i;
	
	i = 1;
	while (i < (ac - 1))
	{
		actuel = *pile_a;
		while (actuel)
		{
			if (actuel->place == (element->place + i))
				return (actuel->position);
			actuel = actuel->next;
		}
		i++;
	}
	return (0);
}