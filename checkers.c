/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilselbon <ilselbon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 16:34:01 by ilselbon          #+#    #+#             */
/*   Updated: 2023/02/18 16:34:02 by ilselbon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

long int	*ft_verif(int nb_de_nb, char **av)
{
	long int	*nombres;

	if (!ft_chiffres(av, 1, 0))
		return (NULL);
	nombres = ft_int_nombres(nb_de_nb, av, (nb_de_nb - 1), 1);
	if (!nombres)
		return (0);
	if (!ft_doublons(nombres, nb_de_nb))
		return (0);
	return (nombres);
}

int	ft_chiffres(char **av, int j, int i)
{
	int	o;

	j = 1;
	while (av[j])
	{
		i = 0;
		while (av[j][i])
		{
			o = 0;
			while (av[j][i] == ' ' && av[j][i] != 0)
				i++;
			if ((av[j][i] == '-' || av[j][i] == '+') && av[j][i] != 0)
			{
				i++;
				o++;
			}
			while ((ft_isdigit(av[j][i]) == 1) && av[j][i++] != 0)
				o--;
			if (((ft_isdigit(av[j][i]) == 0 && av[j][i] != ' ')
					&& av[j][i] != 0) || o > 0)
				return (0);
		}
		j++;
	}
	return (1);
}

int	ft_nombre_de_nombres(char **av)
{
	int	i;
	int	j;
	int	mots;

	j = 1;
	mots = 0;
	while (av[j])
	{
		i = 0;
		while (av[j][i])
		{
			while (av[j][i] && av[j][i] == ' ')
				i++;
			if (av[j][i])
				mots++;
			while (av[j][i] && av[j][i] != ' ')
				i++;
		}
		j++;
	}
	return (mots);
}

long int	*ft_vide_split(int o, char **temp, int i, long int *nombres)
{
	if (i == 1)
	{
		while (o >= 0)
		{
			free(temp[o]);
			o--;
		}
		free(nombres);
	}
	else if (i == 2)
	{
		while (temp[o])
			free(temp[o++]);
	}
	free(temp);
	return (NULL);
}

long int	*ft_int_nombres(int nb_de_nb, char **av, int i, int j)
{
	long int	*nombres;
	char		**temp;
	int			o;

	nombres = (long int *)malloc(sizeof(long int) * (nb_de_nb));
	if (!nombres)
		return (NULL);
	while (i >= 0)
	{
		temp = ft_split(av[j], ' ');
		o = 0;
		while (temp[o] && i >= 0)
		{
			if (!ft_atoi_booleen(temp[o]))
				return (ft_vide_split(o, temp, 1, nombres));
			nombres[i] = ft_atoi_long_int(temp[o]);
			i--;
			o++;
		}
		ft_vide_split(0, temp, 2, nombres);
		j++;
	}	
	return (nombres);
}
