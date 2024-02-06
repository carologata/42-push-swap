/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cogata <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 16:25:44 by cogata            #+#    #+#             */
/*   Updated: 2024/02/06 16:25:45 by cogata           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

long	ft_long_atoi(const char *nptr)
{
	char		*nbr;
	int			i;
	int			sign;
	long int	res;

	nbr = (char *)nptr;
	i = 0;
	sign = 1;
	res = 0;
	while (nbr[i] == 32 || (nbr[i] >= 9 && nbr[i] <= 13))
	{
		i++;
	}
	if (nbr[i] == '-' || nbr[i] == '+')
	{
		if (nbr[i] == '-')
			sign = -1;
		i++;
	}
	while (nbr[i] >= '0' && nbr[i] <= '9')
	{
		res = res * 10 + nbr[i] - '0';
		i++;
	}
	return (res * sign);
}

int	ft_abs(int value)
{
	if (value < 0)
		value *= (-1);
	return (value);
}

int	max_abs(int value1, int value2)
{
	int	value;

	value = ft_abs(value1);
	if (value < ft_abs(value2))
		value = ft_abs(value2);
	return (value);
}

void	message_exit(char *message)
{
	ft_printf("%s\n", message);
	exit(EXIT_FAILURE);
}
