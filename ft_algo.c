#include "header.h"

void afficher_pile(t_list **pile, char c);

void ft_tri_pile_a(t_list **pile_a, t_list **pile_b, int ac)
{
	int i;
	t_list *premier_a;

	i = 0;
	while(i < (ac - 1))
	{
		premier_a = *pile_a;
		if(premier_a->place == (ac - 2) || premier_a->place == (ac - 3) || premier_a->place == (ac - 4))
		{
			ft_ra_rb(pile_a, 'a');
		}
		else if(premier_a->place > (ac/2))
		{
			ft_pa_pb(pile_a, pile_b, 'b');
			ft_ra_rb(pile_b, 'b');
		}
		else if(premier_a->place <= (ac/2))
		{
			ft_pa_pb(pile_a, pile_b, 'b');
		}
		i++;
	}
}