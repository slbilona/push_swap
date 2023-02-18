/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilselbon <ilselbon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 16:46:16 by ilselbon          #+#    #+#             */
/*   Updated: 2023/02/18 16:48:20 by ilselbon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_bonus.h"
#include "../header.h"

void	afficher_pile(t_list **pile_a, t_list **pile_b)
{
	t_list	*p_a;
	t_list	*p_b;

	p_a = *pile_a;
	p_b = *pile_b;
	while (p_a || p_b)
	{
		if (p_a && p_b)
		{
			printf("%d	%d\n", p_a->nombre, p_b->nombre);
			p_a = p_a->next;
			p_b = p_b->next;
		}
		else if (p_a)
		{
			printf("%d\n", p_a->nombre);
			p_a = p_a->next;
		}
		else if (p_b)
		{
			printf("	%d\n", p_b->nombre);
			p_b = p_b->next;
		}
	}
	printf("-	-\na	b\n");
}

void	ft_free_et_exit(char *str, t_list **pile_a, t_list **pile_b)
{
	free(str);
	ft_vide_liste(pile_a);
	ft_vide_liste(pile_b);
	get_next_line(-1);
	exit(EXIT_FAILURE);
}

int	ft_verification(t_list **pile_a, t_list **pile_b)
{
	t_list	*actuel;
	t_list	*temp;

	if ((!*pile_b) && *pile_a)
	{
		temp = *pile_a;
		actuel = temp->next;
		while (actuel)
		{
			if (temp->nombre > actuel->nombre)
				return (1);
			actuel = actuel->next;
			temp = temp->next;
		}
		return (0);
	}
	return (1);
}

void	ft_attribution(char *str, t_list **pile_a, t_list **pile_b)
{
	if (!str)
	{
		if (ft_verification(pile_a, pile_b) == 0)
			printf("OK\n");
		else
			printf("KO\n");
		ft_free_et_exit(str, pile_a, pile_b);
	}
	else if (ft_memcmp(str, "sa\n", ft_strlen(str)) == 0)
		ft_sa_sb_bn(pile_a);
	else if (ft_memcmp(str, "sb\n", ft_strlen(str)) == 0)
		ft_sa_sb_bn(pile_b);
	else if (ft_memcmp(str, "ss\n", ft_strlen(str)) == 0)
		ft_ss_bn(pile_a, pile_b);
	else if (ft_memcmp(str, "ra\n", ft_strlen(str)) == 0)
		ft_ra_rb_bn(pile_a);
	else if (ft_memcmp(str, "rb\n", ft_strlen(str)) == 0)
		ft_ra_rb_bn(pile_b);
	else if (ft_memcmp(str, "rr\n", ft_strlen(str)) == 0)
		ft_ra_rb_bn(pile_a);
	else if (ft_memcmp(str, "pa\n", ft_strlen(str)) == 0)
		ft_pa_pb_bn(pile_b, pile_a);
	else if (ft_memcmp(str, "pb\n", ft_strlen(str)) == 0)
		ft_pa_pb_bn(pile_a, pile_b);
	else if (ft_memcmp(str, "rra\n", ft_strlen(str)) == 0)
		ft_rra_rrb_bn(pile_a);
	else if (ft_memcmp(str, "rrb\n", ft_strlen(str)) == 0)
		ft_rra_rrb_bn(pile_b);
	else if (ft_memcmp(str, "rrr\n", ft_strlen(str)) == 0)
		ft_rrr_bn(pile_a, pile_b);
	else
	{
		printf("Error\n");
		ft_free_et_exit(str, pile_a, pile_b);
	}
}

void	ft_principale_bn(t_list **pile_a, t_list **pile_b)
{
	char	*str;

	str = get_next_line(0);
	ft_attribution(str, pile_a, pile_b);
	free(str);
	ft_principale_bn(pile_a, pile_b);
}
