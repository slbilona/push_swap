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

int			ft_chiffres(char **av);
int			ft_lstsize(t_list *lst);
int			ft_push_swap(int ac, char **av);
int			ft_ordre(int ac, long int *nombres);
int			ft_moyenne(t_list **pile_a, int ac);
int			ft_medianne(t_list **pile_a, int ac);
int			ft_verif_ordre(t_list **pile, char c);
int			ft_doublons(long int *nombres, int ac);
void		ft_ra_rb(t_list **pile, char c);
void		ft_sa_sb(t_list **pile, char c);
void		ft_rra_rrb(t_list **pile, char c);
void		ft_lstadd_front(t_list **lst, t_list *new);
void		ft_pa_pb(t_list **pile1, t_list **pile2, char c);
void		ft_algo(t_list **pile_a, /*t_list **pile_b,*/ int ac);
void		ft_algo_2(t_list **pile_a/*, t_list **pile_b,*/);
void		ft_principale(t_list **pile_a, t_list **pile_b, int ac);
t_list		*ft_lstnew(int content);
t_list		*ft_lstlast(t_list *lst);
t_list		*ft_almostlast(t_list *lst);
t_list		*ft_pile_a(long int *nombres, int ac);
long int	*ft_verif(int ac, char **av);
long int	ft_atoi_long_int(const char *nptr);
long int	*ft_int_nombres(int ac, char **av);

#endif