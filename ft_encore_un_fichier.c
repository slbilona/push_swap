/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_encore_un_fichier.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilselbon <ilselbon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 16:35:48 by ilselbon          #+#    #+#             */
/*   Updated: 2023/02/18 16:36:09 by ilselbon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_list	*ft_choix_b(t_list **pile_a, t_list **pile_b, int nb_de_nb)
{
	t_list	*actuel;
	t_list	*meilleur;
	int		i;
	int		calc;

	actuel = *pile_b;
	meilleur = actuel;
	i = 0;
	calc = ft_calcul(pile_a, actuel, nb_de_nb);
	while (actuel)
	{
		if (actuel->position <= (ft_lstsize(*pile_b) / 2))
			i = actuel->position;
		else
			i = ft_lstsize(*pile_b) - actuel->position;
		if ((ft_calcul(pile_a, actuel, nb_de_nb) + i) < calc)
		{
			meilleur = actuel;
			calc = ft_calcul(pile_a, meilleur, nb_de_nb) + i;
		}
		actuel = actuel->next;
	}
	return (meilleur);
}

void	ft_placer_meileur(t_list *meilleur, t_list **pile_b,
							t_list **pile_a, int nb_de_nb)
{
	int	mouv;
	int	pos_meilleur;
	int	pos_duo;

	pos_duo = ft_duo(pile_a, meilleur, nb_de_nb);
	pos_meilleur = meilleur->position;
	if (pos_meilleur <= (ft_lstsize(*pile_b) / 2))
		while (pos_meilleur--)
			ft_ra_rb(pile_b, 'b');
	else
	{
		mouv = ft_lstsize(*pile_b) - pos_meilleur;
		if (pos_duo > (ft_lstsize(*pile_b) / 2))
		{
			pos_duo = ft_lstsize(*pile_a) - pos_duo;
			while (pos_duo && mouv)
			{
				ft_rrr(pile_a, pile_b);
				mouv--;
				pos_duo--;
			}
		}
		while (mouv--)
			ft_rra_rrb(pile_b, 'b');
	}
}

void	ft_je_sais_pas_ptn(t_list **pile_a, t_list **pile_b, int nb_de_nb)
{
	ft_position(pile_a);
	ft_position(pile_b);
	if (ft_lstsize(*pile_a) != nb_de_nb)
	{
		if (ft_lstsize(*pile_b) == 1)
		{
			ft_clement(pile_a, pile_b);
			ft_pa_pb(pile_b, pile_a, 'a');
			ft_position(pile_a);
			ft_fini_a(pile_a, ft_emplacement(pile_a, 0));
			return ;
		}
		ft_placer_meileur(ft_choix_b(pile_a, pile_b, nb_de_nb),
			pile_b, pile_a, nb_de_nb);
		ft_position(pile_a);
		ft_position(pile_b);
		if ((ft_lstsize(*pile_a) / 2) <= ft_duo(pile_a, *pile_b, nb_de_nb))
			ft_trier_bas(pile_a, pile_b,
				(ft_calcul(pile_a, *pile_b, nb_de_nb) - 1));
		else
			ft_trier_haut(pile_a, pile_b,
				ft_calcul(pile_a, *pile_b, nb_de_nb) - 1);
		ft_je_sais_pas_ptn(pile_a, pile_b, nb_de_nb);
	}
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
	while (i < mouv)
	{
		ft_rra_rrb(pile_a, 'a');
		i++;
	}
	ft_pa_pb(pile_b, pile_a, 'a');
}
