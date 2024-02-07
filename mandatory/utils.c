/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cogata <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 16:21:58 by cogata            #+#    #+#             */
/*   Updated: 2024/02/06 16:21:59 by cogata           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	message_exit(char *message, t_list **mem)
{
	if (message)
	{
		if (ft_strncmp(message, "Error\n", 6) == 0)
			ft_putstr_fd(message, 2);
		else
			ft_printf("%s\n", message);
	}
	if (mem)
		ft_lstclear(mem, free);
	exit(EXIT_FAILURE);
}

void	manage_memory_address(void *address, t_list **mem, char type)
{
	void	**ptr;
	t_list	*new_node;

	ptr = NULL;
	new_node = NULL;
	if (type == '1')
	{
		new_node = ft_lstnew(address);
		ft_lstadd_back(mem, new_node);
	}
	else if (type == '2')
	{
		ptr = (void **)address;
		new_node = ft_lstnew(ptr);
		ft_lstadd_back(mem, new_node);
		while (*ptr)
		{
			new_node = ft_lstnew(*ptr);
			ft_lstadd_back(mem, new_node);
			ptr++;
		}
	}
}
