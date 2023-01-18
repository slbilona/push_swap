/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilselbon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 16:20:44 by ilselbon          #+#    #+#             */
/*   Updated: 2023/01/06 16:20:46 by ilselbon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	afficher_pile(t_list **pile, char c)
{
	t_list	*test;

	test = *pile;
	printf("pile %c :\n", c);
	while (test)
	{
		printf("place : %d, valeur : %d\n",test->place, test->nombre);
		test = test->next;
	}
	printf("\n");
}

int	ft_push_swap(int ac, char **av)
{
	long int	*nombres;
	t_list		*premier_a;
	t_list		*premier_b;
	t_list		*pile_a;

	if (ac <= 1)
		return (1);
	nombres = ft_verif(ac, av);
	if (!nombres)
	{
		printf("error");
		return (1);
	}
	if (!ft_ordre(ac, nombres))
	{
		pile_a = ft_pile_a(nombres, ac);
		premier_a = pile_a;
		premier_b = NULL;
		ft_tri_int(nombres, ac);
		ft_place(nombres, &premier_a, ac);
		if (ac > 6)
		{
			ft_tri_pile_a(&premier_a, &premier_b, ac);
		}
		ft_algo(&premier_a);
		if (premier_b != NULL)
		{
			ft_algo_b(&premier_b);
			if (ft_verif_ordre(&premier_a, 'a')
				&& ft_verif_ordre(&premier_b, 'b'))
			{
				ft_b_dans_a(&premier_a, &premier_b);
			}
		}
		//afficher_pile(&premier_a, 'a');
		//afficher_pile(&premier_b, 'b');
		free(nombres);
	}
	else
	{
		free(nombres);
		return (0);
	}
	ft_vide_liste(&premier_a);
	if (premier_b)
	{
		ft_vide_liste(&premier_b);
	}
	return (0);
}

int	main(int ac, char **av)
{
	ft_push_swap(ac, av);
	return (0);
}
