/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_check_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cogata <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 16:25:01 by cogata            #+#    #+#             */
/*   Updated: 2024/02/06 16:25:02 by cogata           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	check_is_number(char *arg)
{
	int	i;
	int	is_number;

	i = 0;
	is_number = -1;
	if ((arg[i] == '-' || arg[i] == '+') && arg[i + 1])
	{
		i++;
	}
	while (arg[i] != '\0')
	{
		if (arg[i] >= '0' && arg[i] <= '9')
			is_number = 1;
		else
			return (-1);
		i++;
	}
	return (is_number);
}

int	check_arg(t_tree_node *root, char *arg, t_list **mem)
{
	int		i;
	int		is_number;
	long	number;

	i = 1;
	is_number = check_is_number(arg);
	if (is_number == -1)
		message_exit("Error", mem);
	number = ft_long_atoi(arg);
	if (number > 2147483647 || number < -2147483648)
		message_exit("Error", mem);
	if (binary_tree_search(root, number) != -1)
		message_exit("Error", mem);
	return (number);
	i++;
}
