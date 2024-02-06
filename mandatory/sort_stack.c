/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cogata <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 16:20:45 by cogata            #+#    #+#             */
/*   Updated: 2024/02/06 16:20:46 by cogata           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_first_index_pos(t_stack **stack)
{
	t_stack	*temp;
	int		first_index_pos;

	first_index_pos = -1;
	find_position(stack);
	temp = *stack;
	while (temp)
	{
		if (temp->index == 1)
			first_index_pos = temp->pos;
		temp = temp->next;
	}
	return (first_index_pos);
}

void	move_if_necessary(t_stack **head)
{
	int	middle;
	int	first_index_pos;

	middle = (ft_stack_size(*head) / 2) - 1;
	first_index_pos = find_first_index_pos(head);
	while (first_index_pos != 0)
	{
		if (first_index_pos > middle)
			rra(head);
		else
			ra(head);
		first_index_pos = find_first_index_pos(head);
	}
}

void	do_pb_or_ra(t_stack **a, t_stack **b)
{
	int	len;
	int	count;
	int	middle_index;

	len = ft_stack_size(*a);
	count = len;
	middle_index = len / 2;
	while (len > 3 && count > 0)
	{
		if ((*a)->index <= middle_index)
			pb(a, b);
		else
			ra(a);
		len = ft_stack_size(*a);
		count--;
	}
	while (len > 3)
	{
		pb(a, b);
		len = ft_stack_size(*a);
	}
}

void	sort_stack(t_stack **a, t_stack **b)
{
	int	len;
	int	cost_a;
	int	cost_b;

	do_pb_or_ra(a, b);
	sort_three(a);
	len = ft_stack_size(*b);
	while (len != 0)
	{
		find_position(a);
		find_position(b);
		find_target_position(a, b);
		cost_calculate(*a, *b);
		find_lowest_cost(b, &cost_a, &cost_b);
		move(a, b, cost_a, cost_b);
		len = ft_stack_size(*b);
	}
	move_if_necessary(a);
}
