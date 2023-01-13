#include "header.h"

void afficher_pile(t_list **pile, char c);

void ft_algo(t_list **pile_a, t_list **pile_b, int ac)
{
	int moyenne;
	t_list *actuel;
	int i;
	//t_list *dernier;

	i = 0;
	actuel = *pile_a;
	moyenne = ft_moyenne(pile_a, ac);
	printf("\n%d\n", moyenne);
	while(i < ac)
	{
		// afficher_pile(pile_a, 'a');
		// afficher_pile(pile_b, 'b');
		printf("actuel->nombre = %d\n", actuel->nombre);
		//dernier = ft_lstlast(*pile_a);
		if(actuel->nombre < moyenne)
		{
			printf("pa = %d\n", actuel->nombre);
			ft_pa_pb(pile_a, pile_b, 'a');
			actuel = *pile_a;
		}
		// else if((dernier->nombre > moyenne) && (actuel->nombre > dernier->nombre))
		// {
		// 	ft_ra_rb(pile_a, 'a');
		// 	actuel = *pile_a;
		// }
		else
		{
			ft_ra_rb(pile_a, 'a');
			actuel = *pile_a;
		}
		i++;
	}
}

int ft_moyenne(t_list **pile_a, int ac)
{
	int moyenne;
	t_list *actuel;

	actuel = *pile_a;
	moyenne = 0;
	while(actuel)
	{
		moyenne += actuel->nombre;
		actuel = actuel->next;
	}
	moyenne = moyenne / (ac - 1);
	return (moyenne);
}