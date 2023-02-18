/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_index.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilselbon <ilselbon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 16:36:27 by ilselbon          #+#    #+#             */
/*   Updated: 2023/02/18 16:36:28 by ilselbon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

/*
ft_tri_int
ft_place
ft_duo
ft_que_3
*/

void	ft_tri_int(long int *nombres, int nb_de_nb)
{
	int	i;
	int	temp;

	temp = 0;
	i = 0;
	while (i < (nb_de_nb - 1))
	{
		if (nombres[i] > nombres[i + 1])
		{
			temp = nombres[i + 1];
			nombres[i + 1] = nombres[i];
			nombres[i] = temp;
			i = 0;
		}
		else
			i++;
	}
}

void	ft_place(long int *nombres, t_list **pile_a, int nb_de_nb)
{
	t_list	*actuel;
	int		i;

	actuel = *pile_a;
	i = 0;
	while (i < nb_de_nb)
	{
		actuel = *pile_a;
		while (actuel)
		{
			if (nombres[i] == actuel->nombre)
			{
				actuel->place = i;
				actuel = NULL;
			}
			else
				actuel = actuel->next;
		}
		i++;
	}
}

int	ft_duo(t_list **pile_a, t_list *element, int nb_de_nb)
{
	t_list	*actuel;
	int		i;

	i = 1;
	while (i < nb_de_nb)
	{
		actuel = *pile_a;
		while (actuel)
		{
			if (actuel->place == (element->place + i))
				return (actuel->position);
			actuel = actuel->next;
		}
		i++;
	}
	return (0);
}

void	ft_que_3(t_list **pile_a, t_list **pile_b, int nb_de_nb)
{
	t_list	*actuel;
	int		i;

	i = 0;
	while (ft_lstsize(*pile_a) > 3)
	{
		actuel = *pile_a;
		if (actuel->place == (nb_de_nb - 3)
			|| actuel->place == (nb_de_nb - 2)
			||actuel->place == (nb_de_nb - 1))
			ft_ra_rb(pile_a, 'a');
		else if (actuel->place >= ((nb_de_nb - 3) / 2))
			ft_pa_pb(pile_a, pile_b, 'b');
		else
		{
			ft_pa_pb(pile_a, pile_b, 'b');
			ft_ra_rb(pile_b, 'b');
		}
		i++;
	}
}

int	ft_calcul(t_list **pile, t_list *element, int nb_de_nb)
{
	int	compte;

	compte = 0;
	if ((ft_lstsize(*pile) / 2) <= ft_duo(pile, element, nb_de_nb))
		compte = (ft_lstsize(*pile)) - ft_duo(pile, element, nb_de_nb);
	else
		compte = ft_duo(pile, element, nb_de_nb);
	return (compte + 1);
}
