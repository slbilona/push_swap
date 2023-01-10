/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilselbon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 13:28:14 by ilselbon          #+#    #+#             */
/*   Updated: 2023/01/06 13:28:18 by ilselbon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <stdio.h>
# include <stdlib.h>
# include "./Libft_clone/libft.h"

typedef struct s_list
{
	int				nombre;
	struct s_list	*next;
}			t_list;

int			ft_push_swap(int ac, char **av);
long int	*ft_verif(int ac, char **av);
long int	*ft_int_nombres(int ac, char **av);
int			ft_chiffres(char **av);
int			ft_doublons(long int *nombres, int ac);
int			ft_ordre(int ac, long int *nombres);
long int	ft_atoi_long_int(const char *nptr);
t_list		*ft_lstnew(int content);
void		ft_lstadd_front(t_list **lst, t_list *new);
t_list		*ft_pile_a(long int *nombres, int ac);
t_list		*ft_sa_sb(t_list *pile);

#endif