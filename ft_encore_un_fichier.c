#include "header.h"

int ft_choix_b(t_list **pile_a, t_list **pile_b, int ac)
{
    t_list *actuel;
    t_list *meilleur;
    int i;
	int calc;

    actuel = *pile_b;
    meilleur = *pile_b;
    i = 0;
	calc = ft_calcul(pile_a, actuel, ac);
    while (actuel)
    {
        if ((ft_lstsize(*pile_b)/2) <= actuel->position)
            i = (ft_lstsize(*pile_b)) - actuel->position;
        else
            i = actuel->position;
        if ((ft_calcul(pile_a, actuel, ac) + i) < calc)
		{
            calc = (ft_calcul(pile_a, actuel, ac) + i);
			meilleur = actuel;
		}
        actuel = actuel->next;
    }
    return (meilleur->position);
}

void ft_premier_b(t_list **pile_b, int pos)
{
	int mouv;

	mouv = 0;
	if ((ft_lstsize(*pile_b)/2) < pos)
	{
		mouv = pos - (ft_lstsize(*pile_b)/2);
		printf("mouv : %d\n", mouv);
		while(mouv)
		{
			ft_rra_rrb(pile_b, 'b');
			mouv--;
		}
	}
	else
	{
		mouv = pos;
		while(mouv)
		{
			ft_ra_rb(pile_b, 'b');
			mouv--;
		}
	}
}
/*
void ft_je_sais_pas_ptn(t_list **pile_a, t_list **pile_b, int ac)
{
	t_list *premier;
	
	premier = *pile_a;
	if(ft_lstsize(*pile_a) != (ac-1))
	{
		// printf("taille pile a : %d\n", ft_lstsize(*pile_a));
		// printf("calcul 1 : %d\n", ft_calcul(pile_a, *pile_b, ac));
		// printf("calcul 2 : %d\n", (ft_calcul(pile_a, ft_lstlast(*pile_b), ac) + 1));
		ft_position(pile_a);
		ft_position(pile_b);
		printf("meilleur position : %d\n", ft_choix_b(pile_a, pile_b, ac));
		ft_premier_b(pile_b, ft_choix_b(pile_a, pile_b, ac));
		if ((ft_lstsize(*pile_a)/2) <= ft_duo(pile_a, *pile_b, ac))
			ft_trier_bas(pile_a, pile_b, (ft_calcul(pile_a, *pile_b, ac) - 1));
		else
			ft_trier_haut(pile_a, pile_b, ft_calcul(pile_a, *pile_b, ac) - 1);
		ft_je_sais_pas_ptn(pile_a, pile_b, ac);
	}
	else if (premier->place != 0)
	{
		ft_rra_rrb(pile_a, 'a');
		ft_je_sais_pas_ptn(pile_a, pile_b, ac);
	}
}*/