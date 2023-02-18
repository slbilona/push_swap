/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilselbon <ilselbon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 17:12:26 by ilselbon          #+#    #+#             */
/*   Updated: 2023/02/18 19:24:44 by ilselbon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_BONUS_H
# define HEADER_BONUS_H

# include <sys/stat.h>
# include <sys/types.h>
# include <fcntl.h>
# include "../header.h"

// mouvements
void	ft_sa_sb_bn(t_list **pile);
void	ft_ra_rb_bn(t_list **pile);
void	ft_rra_rrb_bn(t_list **pile);
void	ft_rr_bn(t_list **pile_a, t_list **pile_b);
void	ft_ss_bn(t_list **pile_a, t_list **pile_b);
void	ft_rrr_bn(t_list **pile_a, t_list **pile_b);
void	ft_pa_pb_bn(t_list **pile1, t_list **pile2);

//autre
void	ft_principale_bn(t_list **pile_a, t_list **pile_b);

#endif