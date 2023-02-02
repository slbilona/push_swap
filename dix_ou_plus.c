#include "header.h"

/*
ft_principale
ft_clement
ft_fini_a
ft_je_sais_pas_ptn
ft_trier_haut
ft_trier_bas
ft_que_3
ft_position
ft_calcul
ft_duo
*/

void	afficher_pile(t_list **pile, char c);
t_list	*ft_emplacement(t_list **pile_a, int i);

void	ft_principale(t_list **pile_a, t_list **pile_b, int ac)
{
	// afficher_pile(pile_a, 'a');
	// afficher_pile(pile_b, 'b');
	ft_que_3(pile_a, pile_b, ac);
	ft_algo(pile_a);
	ft_je_sais_pas_ptn(pile_a, pile_b, ac);
}

void	ft_clement(t_list **pile_a, t_list **pile_b)
{
	t_list *sup;
	t_list *premier_b;

	premier_b = *pile_b;
	sup = ft_emplacement(pile_a, (premier_b->place + 1));
	ft_position(pile_a);
	if (sup->position != 0)
	{
		if (sup->position <= (ft_lstsize(*pile_a) / 2))
			ft_ra_rb(pile_a, 'a');
		else
			ft_rra_rrb(pile_a, 'a');
		ft_clement(pile_a, pile_b);
	}
	ft_pa_pb(pile_b, pile_a, 'a');
}

t_list	*ft_emplacement(t_list **pile_a, int i)
{
	t_list *actuel;

	actuel = *pile_a;
	while(actuel->place != i)
		actuel = actuel->next;
	return (actuel);
}

void	ft_fini_a(t_list **pile_a, t_list *place_une)
{
	t_list	*premier_a;

	premier_a = *pile_a;
	if (premier_a->place != 0)
	{
		if (place_une->position <= (ft_lstsize(*pile_a) / 2))
			ft_ra_rb(pile_a, 'a');
		else
			ft_rra_rrb(pile_a, 'a');
		ft_fini_a(pile_a, place_une);
	}
}
/*
void	ft_je_sais_pas_ptn(t_list **pile_a, t_list **pile_b, int ac)
{
	t_list *deuxieme_b;
	int un;
	int deux;
	int trois;
	int av_trois;

	un = 1000;
	deux = 1000;
	av_trois = 1000;
	trois = 1000;
	ft_position(pile_a);
	ft_position(pile_b);
	deuxieme_b = *pile_b;
	deuxieme_b = deuxieme_b->next;
	// afficher_pile(pile_a, 'a');
	// afficher_pile(pile_b, 'b');
	if(ft_lstsize(*pile_a) != (ac-1))
	{
		un = ft_calcul(pile_a, *pile_b, ac);
		if (ft_lstsize(*pile_b) >= 2)
		{
			deux = (ft_calcul(pile_a, deuxieme_b, ac) + 1);
			if (ft_lstsize(*pile_b) >= 3)
				trois = (ft_calcul(pile_a, ft_lstlast(*pile_b), ac) + 1);
			if (ft_lstsize(*pile_b) >= 4)
				av_trois = (ft_calcul(pile_a, ft_almostlast(*pile_b), ac) + 2);
		}
		//printf("un : %d, deux : %d, trois : %d\n", un, deux, trois);
		if (ft_lstsize(*pile_b) == 1)
		{
			ft_clement(pile_a, pile_b);
			ft_fini_a(pile_a, ft_emplacement(pile_a, 0));
			return ;
		}
		else if (un <= trois && un <= deux && un <= av_trois)
		{
			if ((ft_lstsize(*pile_a)/2) <= ft_duo(pile_a, *pile_b, ac))
				ft_trier_bas(pile_a, pile_b, (ft_calcul(pile_a, *pile_b, ac) - 1));
			else
				ft_trier_haut(pile_a, pile_b, ft_calcul(pile_a, *pile_b, ac) - 1);
		}
		else if (deux <= un && deux <= trois && deux <= av_trois)
			ft_sa_sb(pile_b, 'b');
		else if (av_trois <= un && av_trois <= deux && av_trois <= trois)
		{
			ft_rra_rrb(pile_b, 'b');
			if ((ft_lstsize(*pile_a)/2) <= ft_duo(pile_a, ft_lstlast(*pile_b), ac))
				ft_rrr(pile_a, pile_b);
			else
				ft_rra_rrb(pile_b, 'b');
		}
		else if (trois <= un && trois <= deux && trois <= av_trois)
		{
			if ((ft_lstsize(*pile_a)/2) <= ft_duo(pile_a, ft_lstlast(*pile_b), ac))
				ft_rrr(pile_a, pile_b);
			else
				ft_rra_rrb(pile_b, 'b');
		}
		ft_je_sais_pas_ptn(pile_a, pile_b, ac);
	}
}*/

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

void	ft_que_3(t_list **pile_a, t_list **pile_b, int ac)
{
	t_list	*actuel;
	int		i;

	i = 0;
	while (ft_lstsize(*pile_a) > 3)
	{
		actuel = *pile_a;
		if (actuel->place == (ac - 4) || actuel->place == (ac - 3) || actuel->place == (ac - 2))
			ft_ra_rb(pile_a, 'a');
		else if (actuel->place >= ((ac-4) /2))
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
	if ((ft_lstsize(*pile) / 2) <= ft_duo(pile, element, ac))
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
