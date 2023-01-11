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

int	ft_push_swap(int ac, char **av)
{
	long int	*nombres;
	void *premier_a;
	void *premier_b;
	t_list *pile_a;
	t_list		*test;
	// t_list		*pile_b;

	if (ac <= 1)
		return (1);
	nombres = ft_verif(ac, av);
	if (!nombres)
		return (1);
	if (!ft_ordre(ac, nombres))
	{
		pile_a = ft_pile_a(nombres, ac);
		premier_a = pile_a;
		premier_b = NULL;
		test = pile_a;
		printf("pile a :");
		while (test)
		{
			printf("%d, ", test->nombre);
			test = test->next;
		}
		printf("\n");
		pile_a = ft_sa_sb(pile_a);
		// pile_a = ft_ra_rb(pile_a);
		// pile_a = ft_rra_rrb(pile_a);
		test = pile_a;
		printf("pile a :");
		while (test)
		{
			printf("%d, ", test->nombre);
			test = test->next;
		}
		printf("\n");
		return (0);
	}
	else
	{
		free(nombres);
		return (0);
	}
	return (0);
}

int	main(int ac, char **av)
{
	ft_push_swap(ac, av);
	return (0);
}

void afficher_pile(t_list *pile, char c)
{
	t_list *test;
	test = pile;
	
	printf("pile %c :");
	while (test)
	{
		printf("%d, ", test->nombre);
		test = test->next;
	}
	printf("\n");
}