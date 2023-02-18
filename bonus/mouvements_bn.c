/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouvements_bn.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilselbon <ilselbon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 17:13:18 by ilselbon          #+#    #+#             */
/*   Updated: 2023/02/18 19:26:53 by ilselbon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"
#include "header_bonus.h"

/*
ft_sa_sb
ft_pa_pb
ft_ra_rb
ft_rra_rrb
ft_almostlast
ft_rrr
*/

void	ft_sa_sb_bn(t_list **pile)
{
	t_list	*chaine1;
	t_list	*chaine2;

	if (ft_lstsize(*pile) >= 2)
	{
		chaine1 = *pile;
		chaine2 = chaine1->next;
		chaine1->next = chaine2->next;
		chaine2->next = *pile;
		*pile = chaine2;
	}
}

void	ft_pa_pb_bn(t_list **pile1, t_list **pile2)
{
	t_list	*chaine1;
	t_list	*chaine2;

	if (*pile1)
	{
		chaine1 = *pile1;
		chaine2 = *pile2;
		*pile2 = chaine1;
		*pile1 = chaine1->next;
		chaine1->next = chaine2;
	}
}

void	ft_ra_rb_bn(t_list **pile)
{
	t_list	*chaine1;
	t_list	*chaine2;
	t_list	*derniere;

	if (ft_lstsize(*pile) >= 3)
	{
		chaine1 = *pile;
		derniere = ft_lstlast(*pile);
		derniere->next = chaine1;
		chaine2 = chaine1->next;
		chaine1->next = NULL;
		*pile = chaine2;
	}
	else if (ft_lstsize(*pile) == 2)
		ft_sa_sb_bn(pile);
}

void	ft_rra_rrb_bn(t_list **pile)
{
	t_list	*chaine1;
	t_list	*av_dernier;
	t_list	*dernier;

	if (*pile)
	{
		if (ft_lstsize(*pile) >= 3)
		{
			dernier = ft_lstlast(*pile);
			chaine1 = *pile;
			av_dernier = ft_almostlast(*pile);
			av_dernier->next = NULL;
			dernier->next = chaine1;
			*pile = dernier;
		}
		else if (ft_lstsize(*pile) == 2)
			ft_sa_sb_bn(pile);
	}
}

void	ft_rrr_bn(t_list **pile_a, t_list **pile_b)
{
	if (*pile_a || *pile_b)
	{
		ft_rra_rrb_bn(pile_a);
		ft_rra_rrb_bn(pile_b);
	}
}
