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

long int	*ft_verif(int ac, char **av)
{
	long int	*nombres;

	if (!ft_chiffres(av))
	{
		//printf("🙁 dsl ma belle 🙁\n");
		return (NULL);
	}
	nombres = ft_int_nombres(ac, av);
	if (!nombres)
	{
		//printf("🙁 dsl ma belle 🙁\n");
		return (0);
	}
	if (!ft_doublons(nombres, ac))
	{
		//printf("🙁 dsl ma belle 🙁\n");
		return (0);
	}
	//printf("🧡 you go girl 🧡\n");
	return (nombres);
}

int	ft_chiffres(char **av)
{
	int	j;
	int	i;
	int	o;

	j = 1;
	o = 0;
	while (av[j])
	{
		i = 0;
		if (av[j][i] == '-' || av[j][i] == '+')
		{
			o++;
			i++;
		}
		while (av[j][i])
		{
			if (ft_isdigit(av[j][i]) == 1)
			{
				i++;
				o--;
			}
			else
				return (0);
		}
		if (o == 1)
			return (0);
		j++;
	}
	return (1);
}

long int	*ft_int_nombres(int ac, char **av)
{
	long int	*nombres;
	int			i;
	int			j;

	i = ac -2;
	j = 1;
	nombres = malloc(sizeof(long int) * (ac - 1));
	if (!nombres)
		return (NULL);
	while (j < ac && i >= 0)
	{
		nombres[i] = ft_atoi_long_int(av[j]);
		if (nombres[i] > 2147483648 || nombres[i--] < -2147483647)
		{
			free(nombres);
			return (NULL);
		}
		j++;
	}
	// i = 0;
	// j = 1;
	// while (j++ < ac)
	// 	printf("%ld, ", nombres[i++]);
	// printf("\n");
	return (nombres);
}

int	ft_doublons(long int *nombres, int ac)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while(i < ac - 1)
	{
		j = i + 1;
		while(j < ac - 1)
		{
			if(nombres[i] == nombres[j])
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

int	ft_ordre(int ac, long int *nombres)
{
	int	i;

	i = 0;
	while (i < (ac - 2))
	{
		if (nombres[i] < nombres[i + 1])
			return (0);
		i++;
	}
	return (1);
}