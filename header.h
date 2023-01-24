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
	int				place;
	int				position;
	struct s_list	*next;
}			t_list;

//parsing
int			ft_chiffres(char **av);
int			ft_ordre(int ac, long int *nombres);
int			ft_verif_ordre(t_list **pile, char c);
int			ft_doublons(long int *nombres, int ac);
long int	*ft_verif(int ac, char **av);

//mouvements
void		ft_ra_rb(t_list **pile, char c);
void		ft_sa_sb(t_list **pile, char c);
void		ft_rra_rrb(t_list **pile, char c);
void		ft_rrr(t_list **pile_a, t_list **pile_b);
void		ft_pa_pb(t_list **pile1, t_list **pile2, char c);

//10 ou moins
void		ft_algo(t_list **pile_a);
void		ft_algo_b(t_list **pile_b);
void		ft_algo_2(t_list **pile_a);
void		ft_algo_2_b(t_list **pile_b);
void		ft_b_dans_a(t_list **pile_a, t_list **pile_b);
void		ft_tri_pile_a(t_list **pile_a, t_list **pile_b, int ac);

//plus de 10
int			ft_duo(t_list **pile_a, t_list *element, int ac);
int			ft_calcul(t_list **pile, t_list *element, int ac);
void		ft_position(t_list **pile);
void 		ft_que_3(t_list **pile_a, t_list **pile_b, int ac);
void		ft_principale(t_list **pile_a, t_list **pile_b, int ac);
void		ft_je_sais_pas_ptn(t_list **pile_a, t_list **pile_b, int ac);
void		ft_trier_bas(t_list **pile_a, t_list **pile_b, int mouv);
void		ft_trier_haut(t_list **pile_a, t_list **pile_b, int mouv);

//autre
int			ft_lstsize(t_list *lst);
int			ft_push_swap(int ac, char **av);
void		ft_vide_liste(t_list **pile);
void		ft_tri_int(long int *nombres, int ac);
void		ft_lstadd_front(t_list **lst, t_list *new);
void		ft_place(long int *nombres, t_list **pile_a, int ac);
t_list		*ft_lstnew(int content);
t_list		*ft_lstlast(t_list *lst);
t_list		*ft_almostlast(t_list *lst);
t_list		*ft_pile_a(long int *nombres, int ac);
long int	ft_atoi_long_int(const char *nptr);
long int	*ft_int_nombres(int ac, char **av);

#endif