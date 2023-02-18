/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilselbon <ilselbon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 17:12:38 by ilselbon          #+#    #+#             */
/*   Updated: 2023/02/18 19:56:00 by ilselbon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"
#include "header_bonus.h"

int	ft_checker(char **av)
{
	long int	*nombres;
	t_list		*pile_a;
	t_list		*premier_a;
	t_list		*premier_b;
	int			nb_de_nb;

	nb_de_nb = ft_nombre_de_nombres(av);
	nombres = ft_verif(nb_de_nb, av);
	if (!nombres)
	{
		ft_printf("Error\n");
		return (free(nombres), 0);
	}
	pile_a = ft_pile_a(nombres, nb_de_nb);
	premier_a = pile_a;
	premier_b = NULL;
	free(nombres);
	ft_principale_bn(&premier_a, &premier_b);
	ft_vide_liste(&premier_a);
	ft_vide_liste(&premier_b);
	return (1);
}

int	main(int ac, char **av)
{
	if (ac >= 2)
	{
		if (ft_checker(av))
			return (0);
		else
			return (1);
	}
}
