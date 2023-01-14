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

void afficher_pile(t_list **pile, char c)
{
	t_list *test;

	test = *pile;
	printf("pile %c :", c);
	while (test)
	{
		printf("%d, ", test->nombre);
		test = test->next;
	}
	printf("\n");
}

int	ft_push_swap(int ac, char **av)
{
	long int	*nombres;
	t_list *premier_a;
	t_list *premier_b;
	t_list *pile_a;
	// t_list *pile_b;

	// pile_b = malloc(sizeof(*pile_b));
	// pile_b->nombre = 10;
	// pile_b->next = NULL;
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
		afficher_pile(&premier_a, 'a');
		afficher_pile(&premier_b, 'b');
		ft_algo(&premier_a, ac);
		afficher_pile(&premier_a, 'a');
		afficher_pile(&premier_b, 'b');
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

