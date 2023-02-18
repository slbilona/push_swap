/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_long_int.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilselbon <ilselbon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 17:43:38 by ilselbon          #+#    #+#             */
/*   Updated: 2023/02/18 16:35:36 by ilselbon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "header.h"

long int	ft_atoi_long_int(const char *nptr)
{
	long int	result;
	int			i;
	int			sign;

	sign = 1;
	i = 0;
	result = 0;
	while ((9 <= nptr[i] && nptr[i] <= 13) || nptr[i] == ' ')
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = sign * -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = result * 10 + nptr[i] - 48;
		i++;
	}
	return (result * sign);
}

int	ft_atoi_booleen(const char *nptr)
{
	long int	result;
	int			i;
	int			sign;

	sign = 1;
	i = 0;
	result = 0;
	while ((9 <= nptr[i] && nptr[i] <= 13) || nptr[i] == ' ')
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = sign * -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = result * 10 + nptr[i] - 48;
		if ((result > INT_MAX || (result * sign) < INT_MIN)
			&& (result * sign) != -2147483648)
			return (0);
		i++;
	}
	return (1);
}
