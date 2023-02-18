/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouvements_bn2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilselbon <ilselbon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 17:14:47 by ilselbon          #+#    #+#             */
/*   Updated: 2023/02/18 19:15:32 by ilselbon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"
#include "header_bonus.h"

void	ft_rr_bn(t_list **pile_a, t_list **pile_b)
{
	if (*pile_a && *pile_b)
	{
		ft_ra_rb_bn(pile_a);
		ft_ra_rb_bn(pile_b);
	}
}

void	ft_ss_bn(t_list **pile_a, t_list **pile_b)
{
	if (*pile_a || *pile_b)
	{
		ft_sa_sb_bn(pile_a);
		ft_sa_sb_bn(pile_b);
	}
}
