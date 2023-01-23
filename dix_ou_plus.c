#include "header.h"

void	afficher_pile(t_list **pile, char c);

void	ft_principale(t_list **pile_a, t_list **pile_b, int ac)
{
	afficher_pile(pile_a, 'a');
	afficher_pile(pile_b, 'b');
	ft_que_3(pile_a, pile_b, ac);
	ft_algo(pile_a);
	ft_position(pile_a);
	ft_je_sais_pas_ptn(pile_a, pile_b, ac);
}

void ft_je_sais_pas_ptn(t_list **pile_a, t_list **pile_b, int ac)
{
	printf("taille pile a : %d\n", ft_lstsize(*pile_a));
	printf("calcul 1 : %d\n", ft_calcul(pile_a, *pile_b, ac));
	printf("calcul 2 : %d\n", (ft_calcul(pile_a, ft_lstlast(*pile_b), ac) + 1));
	if (ft_calcul(pile_a, *pile_b, ac) == (ft_calcul(pile_a, ft_lstlast(*pile_b), ac) + 1))
	{
		printf("1\n");
		ft_trier_haut(pile_a, pile_b, ft_calcul(pile_a, *pile_b, ac) - 1);
	}
	else if (ft_calcul(pile_a, *pile_b, ac) > (ft_calcul(pile_a, ft_lstlast(*pile_b), ac) + 1))
	{
		printf("2\n");
		ft_trier_bas(pile_a, pile_b, ft_calcul(pile_a, *pile_b, ac) - 1);
	}
	else if (ft_calcul(pile_a, *pile_b, ac) < (ft_calcul(pile_a, ft_lstlast(*pile_b), ac) + 1))
	{
		printf("3\n");
		ft_trier_haut(pile_a, pile_b, ft_calcul(pile_a, *pile_b, ac) - 1);
	}
	ft_position(pile_a);

	printf("taille pile a : %d\n", ft_lstsize(*pile_a));
	printf("calcul 1 : %d\n", ft_calcul(pile_a, *pile_b, ac));
	printf("calcul 2 : %d\n", (ft_calcul(pile_a, ft_lstlast(*pile_b), ac) + 1));
	if (ft_calcul(pile_a, *pile_b, ac) == (ft_calcul(pile_a, ft_lstlast(*pile_b), ac) + 1))
	{
		printf("1\n");
		ft_trier_haut(pile_a, pile_b, ft_calcul(pile_a, *pile_b, ac) - 1);
	}
	else if (ft_calcul(pile_a, *pile_b, ac) > (ft_calcul(pile_a, ft_lstlast(*pile_b), ac) + 1))
	{
		printf("2\n");
		ft_trier_bas(pile_a, pile_b, ft_calcul(pile_a, *pile_b, ac) - 1);
	}
	else if (ft_calcul(pile_a, *pile_b, ac) < (ft_calcul(pile_a, ft_lstlast(*pile_b), ac) + 1))
	{
		printf("3\n");
		ft_trier_haut(pile_a, pile_b, ft_calcul(pile_a, *pile_b, ac) - 1);
	}
	ft_position(pile_a);

	printf("taille pile a : %d\n", ft_lstsize(*pile_a));
	printf("calcul 1 : %d\n", ft_calcul(pile_a, *pile_b, ac));
	printf("calcul 2 : %d\n", (ft_calcul(pile_a, ft_lstlast(*pile_b), ac) + 1));
	if (ft_calcul(pile_a, *pile_b, ac) == (ft_calcul(pile_a, ft_lstlast(*pile_b), ac) + 1))
	{
		printf("1\n");
		ft_trier_haut(pile_a, pile_b, ft_calcul(pile_a, *pile_b, ac) - 1);
	}
	else if (ft_calcul(pile_a, *pile_b, ac) > (ft_calcul(pile_a, ft_lstlast(*pile_b), ac) + 1))
	{
		printf("2\n");
		ft_trier_bas(pile_a, pile_b, ft_calcul(pile_a, *pile_b, ac) - 1);
	}
	else if (ft_calcul(pile_a, *pile_b, ac) < (ft_calcul(pile_a, ft_lstlast(*pile_b), ac) + 1))
	{
		printf("3\n");
		ft_trier_haut(pile_a, pile_b, ft_calcul(pile_a, *pile_b, ac) - 1);
	}
	ft_position(pile_a);

	printf("taille pile a : %d\n", ft_lstsize(*pile_a));
	printf("calcul 1 : %d\n", ft_calcul(pile_a, *pile_b, ac));
	printf("calcul 2 : %d\n", (ft_calcul(pile_a, ft_lstlast(*pile_b), ac) + 1));
	if (ft_calcul(pile_a, *pile_b, ac) == (ft_calcul(pile_a, ft_lstlast(*pile_b), ac) + 1))
	{
		printf("1\n");
		ft_trier_haut(pile_a, pile_b, ft_calcul(pile_a, *pile_b, ac) - 1);
	}
	else if (ft_calcul(pile_a, *pile_b, ac) > (ft_calcul(pile_a, ft_lstlast(*pile_b), ac) + 1))
	{
		printf("2\n");
		ft_trier_bas(pile_a, pile_b, ft_calcul(pile_a, *pile_b, ac) - 1);
	}
	else if (ft_calcul(pile_a, *pile_b, ac) < (ft_calcul(pile_a, ft_lstlast(*pile_b), ac) + 1))
	{
		printf("3\n");
		ft_trier_haut(pile_a, pile_b, ft_calcul(pile_a, *pile_b, ac) - 1);
	}
	ft_position(pile_a);

	printf("taille pile a : %d\n", ft_lstsize(*pile_a));
	printf("calcul 1 : %d\n", ft_calcul(pile_a, *pile_b, ac));
	printf("calcul 2 : %d\n", (ft_calcul(pile_a, ft_lstlast(*pile_b), ac) + 1));
	if (ft_calcul(pile_a, *pile_b, ac) == (ft_calcul(pile_a, ft_lstlast(*pile_b), ac) + 1))
	{
		printf("1\n");
		ft_trier_haut(pile_a, pile_b, ft_calcul(pile_a, *pile_b, ac) - 1);
	}
	else if (ft_calcul(pile_a, *pile_b, ac) > (ft_calcul(pile_a, ft_lstlast(*pile_b), ac) + 1))
	{
		printf("2\n");
		ft_trier_bas(pile_a, pile_b, ft_calcul(pile_a, *pile_b, ac) - 1);
	}
	else if (ft_calcul(pile_a, *pile_b, ac) < (ft_calcul(pile_a, ft_lstlast(*pile_b), ac) + 1))
	{
		printf("3\n");
		ft_trier_haut(pile_a, pile_b, ft_calcul(pile_a, *pile_b, ac) - 1);
	}
	ft_position(pile_a);

	printf("taille pile a : %d\n", ft_lstsize(*pile_a));
	printf("calcul 1 : %d\n", ft_calcul(pile_a, *pile_b, ac));
	printf("calcul 2 : %d\n", (ft_calcul(pile_a, ft_lstlast(*pile_b), ac) + 1));
	if (ft_calcul(pile_a, *pile_b, ac) == (ft_calcul(pile_a, ft_lstlast(*pile_b), ac) + 1))
	{
		printf("1\n");
		ft_trier_haut(pile_a, pile_b, ft_calcul(pile_a, *pile_b, ac) - 1);
	}
	else if (ft_calcul(pile_a, *pile_b, ac) > (ft_calcul(pile_a, ft_lstlast(*pile_b), ac) + 1))
	{
		printf("2\n");
		ft_trier_bas(pile_a, pile_b, ft_calcul(pile_a, *pile_b, ac) - 1);
	}
	else if (ft_calcul(pile_a, *pile_b, ac) < (ft_calcul(pile_a, ft_lstlast(*pile_b), ac) + 1))
	{
		printf("3\n");
		ft_trier_haut(pile_a, pile_b, ft_calcul(pile_a, *pile_b, ac) - 1);
	}
	ft_position(pile_a);

	printf("taille pile a : %d\n", ft_lstsize(*pile_a));
	printf("calcul 1 : %d\n", ft_calcul(pile_a, *pile_b, ac));
	printf("calcul 2 : %d\n", (ft_calcul(pile_a, ft_lstlast(*pile_b), ac) + 1));
	if (ft_calcul(pile_a, *pile_b, ac) == (ft_calcul(pile_a, ft_lstlast(*pile_b), ac) + 1))
	{
		printf("1\n");
		ft_trier_haut(pile_a, pile_b, ft_calcul(pile_a, *pile_b, ac) - 1);
	}
	else if (ft_calcul(pile_a, *pile_b, ac) > (ft_calcul(pile_a, ft_lstlast(*pile_b), ac) + 1))
	{
		printf("2\n");
		ft_trier_bas(pile_a, pile_b, ft_calcul(pile_a, *pile_b, ac) - 1);
	}
	else if (ft_calcul(pile_a, *pile_b, ac) < (ft_calcul(pile_a, ft_lstlast(*pile_b), ac) + 1))
	{
		printf("3\n");
		ft_trier_haut(pile_a, pile_b, ft_calcul(pile_a, *pile_b, ac) - 1);
	}
	ft_position(pile_a);

	printf("taille pile a : %d\n", ft_lstsize(*pile_a));
	printf("calcul 1 : %d\n", ft_calcul(pile_a, *pile_b, ac));
	printf("calcul 2 : %d\n", (ft_calcul(pile_a, ft_lstlast(*pile_b), ac) + 1));
	if (ft_calcul(pile_a, *pile_b, ac) == (ft_calcul(pile_a, ft_lstlast(*pile_b), ac) + 1))
	{
		printf("1\n");
		ft_trier_haut(pile_a, pile_b, ft_calcul(pile_a, *pile_b, ac) - 1);
	}
	else if (ft_calcul(pile_a, *pile_b, ac) > (ft_calcul(pile_a, ft_lstlast(*pile_b), ac) + 1))
	{
		printf("2\n");
		ft_trier_bas(pile_a, pile_b, ft_calcul(pile_a, *pile_b, ac) - 1);
	}
	else if (ft_calcul(pile_a, *pile_b, ac) < (ft_calcul(pile_a, ft_lstlast(*pile_b), ac) + 1))
	{
		printf("3\n");
		ft_trier_haut(pile_a, pile_b, ft_calcul(pile_a, *pile_b, ac) - 1);
	}
	ft_position(pile_a);

	printf("taille pile a : %d\n", ft_lstsize(*pile_a));
	printf("calcul 1 : %d\n", ft_calcul(pile_a, *pile_b, ac));
	printf("calcul 2 : %d\n", (ft_calcul(pile_a, ft_lstlast(*pile_b), ac) + 1));
	if (ft_calcul(pile_a, *pile_b, ac) == (ft_calcul(pile_a, ft_lstlast(*pile_b), ac) + 1))
	{
		printf("1\n");
		ft_trier_haut(pile_a, pile_b, ft_calcul(pile_a, *pile_b, ac) - 1);
	}
	else if (ft_calcul(pile_a, *pile_b, ac) > (ft_calcul(pile_a, ft_lstlast(*pile_b), ac) + 1))
	{
		printf("2\n");
		ft_trier_bas(pile_a, pile_b, ft_calcul(pile_a, *pile_b, ac) - 1);
	}
	else if (ft_calcul(pile_a, *pile_b, ac) < (ft_calcul(pile_a, ft_lstlast(*pile_b), ac) + 1))
	{
		printf("3\n");
		ft_trier_haut(pile_a, pile_b, ft_calcul(pile_a, *pile_b, ac) - 1);
	}
	ft_position(pile_a);
}

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
	ft_rra_rrb(pile_b, 'b');
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