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

	if (ac <= 1)
		return (1);
	nombres = ft_verif(ac, av);
	if (!nombres)
		return (1);
	if (!ft_ordre(ac, nombres))
	{
		printf("🙁 pas dans l'ordre ma jolie 🙁\n");
		return (0);
	}
	return (0);
}

int	main(int ac, char **av)
{
	ft_push_swap(ac, av);
	return (0);
}
