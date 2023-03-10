/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listes_chainees.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilselbon <ilselbon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 16:37:30 by ilselbon          #+#    #+#             */
/*   Updated: 2023/02/18 16:38:30 by ilselbon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

/*
	ft_pile_a
	ft_lstnew
	ft_lstadd_front
	ft_lstsize
	ft_lstlast
	ft_vide_liste
*/

t_list	*ft_pile_a(long int *nombres, int nb_de_nb)
{
	t_list	*list;
	int		i;

	i = 0;
	list = ft_lstnew(nombres[i]);
	i++;
	while (i < nb_de_nb)
	{
		ft_lstadd_front(&list, ft_lstnew(nombres[i]));
		i++;
	}
	return (list);
}

t_list	*ft_lstnew(int content)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->nombre = content;
	new->next = NULL;
	return (new);
}

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	t_list	*actuel;

	if (!*lst)
		*lst = new;
	else
	{
		actuel = *lst;
		*lst = new;
		new->next = actuel;
	}
}

int	ft_lstsize(t_list *lst)
{
	t_list	*actuel;
	int		i;

	actuel = lst;
	if (actuel)
		i = 1;
	else
		return (0);
	while (actuel->next)
	{
		actuel = actuel->next;
		i++;
	}
	return (i);
}

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*actuel;
	t_list	*temp;

	actuel = lst;
	if (!lst)
		return (NULL);
	while (actuel)
	{
		temp = actuel;
		actuel = actuel->next;
	}
	return (temp);
}
