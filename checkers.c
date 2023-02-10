/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilselbon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 13:27:39 by ilselbon          #+#    #+#             */
/*   Updated: 2023/01/06 13:27:44 by ilselbon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

long int	*ft_verif(int nb_de_nb, char **av)
{
	long int	*nombres;

	if (!ft_chiffres(av))
		return (NULL);
	nombres = ft_int_nombres(nb_de_nb, av);
	if (!nombres)
		return (0);
	if (!ft_doublons(nombres, nb_de_nb))
		return (0);
	return (nombres);
}

int	ft_chiffres(char **av)
{
	int	j;
	int	i;
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
			while ((ft_isdigit(av[j][i]) == 1) && av[j][i] != 0)
			{
				i++;
				o--;
			}
			if ((ft_isdigit(av[j][i]) == 0 && av[j][i] != ' ') && av[j][i] != 0)
				return (0);
			if (o > 0)
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

long int	*ft_int_nombres(int nombre, char **av)
{
	long int	*nombres;
	char		**temp;
	int			i;
	int			j;
	int			o;

	i = nombre - 1;
	j = 1;
	nombres = (long int *)malloc(sizeof(long int) * (nombre));
	if (!nombres)
		return (NULL);
	while (i >= 0)
	{
		temp = ft_split(av[j], ' ');
		o = 0;
		while (temp[o] && i >= 0)
		{
			nombres[i] = ft_atoi_long_int(temp[o]);
			if (nombres[i] > 2147483648 || nombres[i] < -2147483647)
			{
				while (o >= 0)
				{
					free(temp[o]);
					o--;
				}
				free(temp);
				free(nombres);
				return (NULL);
			}
			i--;
			o++;
		}
		o = 0;
		while (temp[o])
			free(temp[o++]);
		free(temp);
		j++;
	}	
	return (nombres);
}

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
	while (i < (taille - 1))
	{
		if (nombres[i] < nombres[i + 1])
			return (0);
		i++;
	}
	return (1);
}
