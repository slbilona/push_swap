#ifndef HEADER_BONUS_H
# define HEADER_BONUS_H

# include <sys/stat.h>
# include <sys/types.h>
# include <fcntl.h>
# include "header.h"

// mouvements
void	ft_sa_sb_bn(t_list **pile);
void	ft_pa_pb_bn(t_list **pile1, t_list **pile2);
void	ft_ra_rb_bn(t_list **pile);
void	ft_rra_rrb_bn(t_list **pile);
void	ft_rrr_bn(t_list **pile_a, t_list **pile_b);


#endif