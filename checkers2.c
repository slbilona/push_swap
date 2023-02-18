#include "header.h"

int	ft_doublons(long int *nombres, int nb_de_nb)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < (nb_de_nb - 1))
	{
		j = i + 1;
		while (j < nb_de_nb)
		{
			if (nombres[i] == nombres[j])
			{
				free(nombres);
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_ordre(int taille, long int *nombres)
{
	int	i;

	i = 0;
	if (!nombres)
		return (1);
	while (i < (taille - 1))
	{
		if (nombres[i] < nombres[i + 1])
			return (0);
		i++;
	}
	return (1);
}
