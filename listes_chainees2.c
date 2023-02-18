/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listes_chainees2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilselbon <ilselbon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 16:38:01 by ilselbon          #+#    #+#             */
/*   Updated: 2023/02/18 16:38:50 by ilselbon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_vide_liste(t_list **pile)
{
	t_list	*actuel;
	t_list	*temp;

	actuel = *pile;
	while (actuel)
	{
		temp = actuel;
		actuel = actuel->next;
		free(temp);
	}
}

t_list	*ft_almostlast(t_list *lst)
{
	t_list	*actuel;
	t_list	*temp;
	t_list	*pretemp;

	actuel = lst;
	temp = NULL;
	if (!lst)
		return (NULL);
	while (actuel)
	{
		pretemp = temp;
		temp = actuel;
		actuel = actuel->next;
	}
	return (pretemp);
}
