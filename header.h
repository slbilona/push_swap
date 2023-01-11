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
int			ft_chiffres(char **av);
int			ft_doublons(long int *nombres, int ac);
int			ft_ordre(int ac, long int *nombres);
int			ft_lstsize(t_list *lst);
void		ft_lstadd_front(t_list **lst, t_list *new);
t_list		*ft_lstnew(int content);
t_list		*ft_pile_a(long int *nombres, int ac);
t_list		*ft_sa_sb(t_list *pile);
t_list		*ft_pa_pb(t_list *pile1, t_list *pile_b);
t_list		*ft_lstlast(t_list *lst);
t_list		*ft_ra_rb(t_list *pile);
t_list *ft_rra_rrb(t_list *pile);
t_list *ft_almostlast(t_list *lst);
long int	*ft_verif(int ac, char **av);
long int	*ft_int_nombres(int ac, char **av);
long int	ft_atoi_long_int(const char *nptr);

#endif