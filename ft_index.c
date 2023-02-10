#include "header.h"

/*
ft_tri_int
ft_place
*/

void	ft_tri_int(long int *nombres, int nb_de_nb)
{
	int	i;
	int	temp;

	temp = 0;
	i = 0;
	while (i < (nb_de_nb - 1))
	{
		if (nombres[i] > nombres[i + 1])
		{
			temp = nombres[i + 1];
			nombres[i + 1] = nombres[i];
			nombres[i] = temp;
			i = 0;
		}
		else
			i++;
	}
}

void	ft_place(long int *nombres, t_list **pile_a, int nb_de_nb)
{
	t_list	*actuel;
	int		i;

	actuel = *pile_a;
	i = 0;
	while (i < nb_de_nb)
	{
		actuel = *pile_a;
		while (actuel)
		{
			if (nombres[i] == actuel->nombre)
			{
				actuel->place = i;
				actuel = NULL;
			}
			else
				actuel = actuel->next;
		}
		i++;
	}
}

int	ft_duo(t_list **pile_a, t_list *element, int nb_de_nb)
{
	t_list	*actuel;
	int		i;

	i = 1;
	while (i < nb_de_nb)
	{
		actuel = *pile_a;
		while (actuel)
		{
			if (actuel->place == (element->place + i))
				return (actuel->position);
			actuel = actuel->next;
		}
		i++;
	}
	return (0);
}

