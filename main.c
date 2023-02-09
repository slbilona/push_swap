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

void	afficher_pile(t_list **pile, char c);

void	afficher_pile(t_list **pile, char c)
{
	t_list	*test;

	test = *pile;
	printf("pile %c :\n", c);
	while (test)
	{
		printf("position : %d, place : %d, valeur : %d\n", test->position, test->place, test->nombre);
		test = test->next;
	}
	printf("\n");
}

int	ft_push_swap(char **av)
{
	long int	*nombres;
	t_list		*premier_a;
	t_list		*premier_b;
	t_list		*pile_a;
	int			nb_de_nb;

	nb_de_nb = ft_nombre_de_nombres(av);
	nombres = ft_verif(nb_de_nb, av);
	if (!nombres)
	{
		printf("error");
		return (1);
	}
	if (!ft_ordre(nb_de_nb, nombres))
	{
		pile_a = ft_pile_a(nombres, nb_de_nb);
		premier_a = pile_a;
		//afficher_pile(&premier_a, 'a');
		premier_b = NULL;
		ft_tri_int(nombres, nb_de_nb);
		ft_place(nombres, &premier_a, nb_de_nb);
		if (nb_de_nb <= 10)
		{
			ft_tri_pile_a(&premier_a, &premier_b, nb_de_nb);
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
		}
		else
			ft_principale(&premier_a, &premier_b, nb_de_nb);
		free(nombres);
	}
	else
		return (free(nombres), 0);
	ft_vide_liste(&premier_a);
	if (premier_b)
	{
		ft_vide_liste(&premier_b);
	}
	return (0);
}

int	main(int ac, char **av)
{
	if(ac >= 2)
	{
		ft_push_swap(av);
	}
	// if (ac >= 2)
	// {
	// 	long int *nombres = ft_verif(ft_nombre_de_nombres(av), av);
	// 	if(nombres)
	// 		printf("%d\n", ft_ordre(ft_nombre_de_nombres(av), nombres));
	// 	free(nombres);
	// }
	// return (0);
}
