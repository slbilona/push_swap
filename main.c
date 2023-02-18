/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilselbon <ilselbon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 16:20:44 by ilselbon          #+#    #+#             */
/*   Updated: 2023/02/18 20:09:42 by ilselbon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	ft_push_swap(int nb_de_nb, char **av)
{
	long int	*nombres;
	t_list		*premier_a;
	t_list		*premier_b;
	t_list		*pile_a;

	nombres = ft_verif(nb_de_nb, av);
	if (!nombres)
	{
		ft_printf("Error\n");
		return (1);
	}
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
	}
	return (free(nombres), 0);
}

int	main(int ac, char **av)
{
	int			nb_de_nb;

	if (ac >= 2)
	{
		nb_de_nb = ft_nombre_de_nombres(av);
		if (ft_push_swap(nb_de_nb, av))
			return (1);
		else
			return (0);
	}
}
