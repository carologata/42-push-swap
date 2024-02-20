/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cogata <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 11:44:30 by cogata            #+#    #+#             */
/*   Updated: 2024/02/07 11:44:35 by cogata           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*fill_stack_a(char *argv[], int i, t_list **mem)
{
	t_stack	*a;
	t_stack	*temp;

	a = NULL;
	while (argv[i])
	{
		temp = ft_stack_new(ft_atoi(argv[i]));
		garbage_collector(temp, mem, POINTER);
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
			message_exit(NULL, mem);
		a = a->next;
	}
}
