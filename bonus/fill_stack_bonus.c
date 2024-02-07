/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cogata <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 12:03:27 by cogata            #+#    #+#             */
/*   Updated: 2024/02/07 12:03:30 by cogata           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

t_stack	*fill_stack_a(char *argv[], int i, t_list **mem)
{
	t_stack	*a;
	t_stack	*temp;

	a = NULL;
	while (argv[i])
	{
		temp = ft_stack_new(ft_atoi(argv[i]));
		manage_memory_address(temp, mem, '1');
		ft_stack_add_back(&a, temp);
		i++;
	}
	return (a);
}

void	fill_with_index(t_stack *a, t_tree_node *root, t_list **mem)
{
	while (a)
	{
		a->index = binary_tree_search(root, a->value);
		if (a->index == -1)
			message_exit("Error", mem);
		a = a->next;
	}
}
