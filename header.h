/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilselbon <ilselbon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 13:28:14 by ilselbon          #+#    #+#             */
/*   Updated: 2023/02/18 16:37:21 by ilselbon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include "./Libft_clone/libft.h"

typedef struct s_list
{
	int				nombre;
	int				place;
	int				position;
	struct s_list	*next;
}			t_list;

//parsing
int			ft_chiffres(char **av, int j, int i);
int			ft_ordre(int taille, long int *nombres);
int			ft_verif_ordre(t_list **pile, char c);
int			ft_doublons(long int *nombres, int nb_de_nb);
long int	*ft_verif(int nb_de_nb, char **av);
long int	*ft_int_nombres(int nb_de_nb, char **av, int i, int j);
long int	*ft_vide_split(int o, char **temp, int i, long int *nombres);

//mouvements
void		ft_ra_rb(t_list **pile, char c);
void		ft_sa_sb(t_list **pile, char c);
void		ft_rra_rrb(t_list **pile, char c);
void		ft_rrr(t_list **pile_a, t_list **pile_b);
void		ft_pa_pb(t_list **pile1, t_list **pile2, char c);

//algo
int			ft_nombre_de_nombres(char **av);
int			ft_duo(t_list **pile_a, t_list *element, int nb_de_nb);
int			ft_calcul(t_list **pile, t_list *element, int nb_de_nb);
void		ft_algo(t_list **pile_a);
void		ft_position(t_list **pile);
void		ft_que_3(t_list **pile_a, t_list **pile_b, int ac);
void		ft_principale(t_list **pile_a, t_list **pile_b, int ac);
void		ft_je_sais_pas_ptn(t_list **pile_a, t_list **pile_b, int nb_de_nb);
void		ft_trier_bas(t_list **pile_a, t_list **pile_b, int mouv);
void		ft_trier_haut(t_list **pile_a, t_list **pile_b, int mouv);
void		ft_fini_a(t_list **pile_a, t_list *place_une);
void		ft_clement(t_list **pile_a, t_list **pile_b);
t_list		*ft_emplacement(t_list **pile_a, int i);
t_list		*ft_choix_b(t_list **pile_a, t_list **pile_b, int nb_de_nb);
void		ft_placer_meileur(t_list *meilleur, t_list **pile_b,
				t_list **pile_a, int nb_de_nb);

//listes chainees
int			ft_lstsize(t_list *lst);
void		ft_vide_liste(t_list **pile);
void		ft_lstadd_front(t_list **lst, t_list *new);
t_list		*ft_lstnew(int content);
t_list		*ft_lstlast(t_list *lst);
t_list		*ft_almostlast(t_list *lst);

//autre
int			ft_push_swap(char **av);
int			ft_atoi_booleen(const char *nptr);
void		ft_tri_int(long int *nombres, int nb_de_nb);
void		ft_place(long int *nombres, t_list **pile_a, int nb_de_nb);
t_list		*ft_pile_a(long int *nombres, int nb_de_nb);
long int	ft_atoi_long_int(const char *nptr);

#endif