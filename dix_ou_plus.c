/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dix_ou_plus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilselbon <ilselbon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 16:34:25 by ilselbon          #+#    #+#             */
/*   Updated: 2023/02/18 16:34:26 by ilselbon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

/*
ft_principale
ft_clement
ft_fini_a
ft_je_sais_pas_ptn
ft_trier_haut
ft_trier_bas
ft_position
*/

void	ft_principale(t_list **pile_a, t_list **pile_b, int nb_de_nb)
{
	ft_que_3(pile_a, pile_b, nb_de_nb);
	ft_algo(pile_a);
	ft_je_sais_pas_ptn(pile_a, pile_b, nb_de_nb);
}

void	ft_clement(t_list **pile_a, t_list **pile_b)
{
	t_list	*sup;
	t_list	*premier_b;

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
}

t_list	*ft_emplacement(t_list **pile_a, int i)
{
	t_list	*actuel;

	actuel = *pile_a;
	while (actuel->place != i)
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

void	ft_position(t_list **pile)
{
	t_list	*actuel;
	int		i;

	i = 0;
	actuel = *pile;
	while (actuel)
	{
		actuel->position = i;
		actuel = actuel->next;
		i++;
	}
}
