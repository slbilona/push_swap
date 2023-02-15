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
		printf("Error\n");
	if (!ft_ordre(nb_de_nb, nombres))
	{
		pile_a = ft_pile_a(nombres, nb_de_nb);
		premier_a = pile_a;
		premier_b = NULL;
		ft_tri_int(nombres, nb_de_nb);
		ft_place(nombres, &premier_a, nb_de_nb);
		if (nb_de_nb == 3)
			ft_algo(&premier_a);
		ft_principale(&premier_a, &premier_b, nb_de_nb);
		ft_vide_liste(&premier_a);
		ft_vide_liste(&premier_b);
		free(nombres);
	}
	return (0);
}

int	main(int ac, char **av)
{
	if (ac >= 2)
	{
		ft_push_swap(av);
	}
}
