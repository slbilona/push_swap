#include "header.h"

int ft_choix_b(t_list **pile_a,t_list **pile_b, int ac)
{
	t_list *actuel;
	t_list *meilleur;
	int i;
	int calc;

	actuel  = *pile_b;
	meilleur = actuel;
	i = 0;
	calc = ft_calcul(pile_a, actuel, ac);
	while(actuel)
	{
		if (actuel->position <= (ft_lstsize(*pile_b) / 2))
			i = actuel->position;
		else
			i = ft_lstsize(*pile_b) - actuel->position;
		//printf("%d\n", (ft_calcul(pile_a, actuel, ac) + i));
		if ((ft_calcul(pile_a, actuel, ac) + i) < calc)
		{
			meilleur = actuel;
			calc = ft_calcul(pile_a, meilleur, ac) + i;
		}
		actuel = actuel->next;
	}
	return (meilleur->position);
}

void ft_placer_meileur(int pos_meilleur, t_list **pile_b)
{
	int mouv;

	if (pos_meilleur <= (ft_lstsize(*pile_b) / 2))
	{
		mouv = pos_meilleur;
		while(mouv)
		{
			ft_ra_rb(pile_b, 'b');
			mouv--;
		}
	}
	else
	{
		mouv = ft_lstsize(*pile_b) - pos_meilleur;
		while(mouv)
		{
			ft_rra_rrb(pile_b, 'b');
			mouv--;
		}
	}
}

void	ft_je_sais_pas_ptn(t_list **pile_a, t_list **pile_b, int ac)
{
	ft_position(pile_a);
	ft_position(pile_b);
	if(ft_lstsize(*pile_a) != (ac-1))
	{
		if (ft_lstsize(*pile_b) == 1)
		{
			ft_clement(pile_a, pile_b);
			ft_fini_a(pile_a, ft_emplacement(pile_a, 0));
			return ;
		}
		ft_placer_meileur(ft_choix_b(pile_a, pile_b, ac), pile_b);
		if ((ft_lstsize(*pile_a)/2) <= ft_duo(pile_a, *pile_b, ac))
			ft_trier_bas(pile_a, pile_b, (ft_calcul(pile_a, *pile_b, ac) - 1));
		else
			ft_trier_haut(pile_a, pile_b, ft_calcul(pile_a, *pile_b, ac) - 1);
		ft_je_sais_pas_ptn(pile_a, pile_b, ac);
	}
}