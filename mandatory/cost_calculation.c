/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_calculation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cogata <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 16:19:20 by cogata            #+#    #+#             */
/*   Updated: 2024/02/06 16:19:22 by cogata           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	cost_calculate(t_stack *a, t_stack *b)
{
	int	length_a;
	int	middle_a;
	int	length_b;
	int	middle_b;

	length_a = ft_stack_size(a);
	middle_a = (length_a / 2) - 1;
	length_b = ft_stack_size(b);
	middle_b = (length_b / 2) - 1;
	while (b)
	{
		b->cost_a = b->target_pos;
		if (b->target_pos > middle_a)
			b->cost_a = (length_a - b->target_pos) * (-1);
		b->cost_b = b->pos;
		if (b->pos > middle_b)
			b->cost_b = (length_b - b->pos) * (-1);
		b = b->next;
	}
}

void	find_lowest_cost(t_stack **b, int *cost_a, int *cost_b)
{
	int		cost;
	int		lowest_cost;
	t_stack	*temp_b;

	cost = 0;
	temp_b = *b;
	lowest_cost = INT_MAX;
	while (temp_b)
	{
		if ((temp_b->cost_a > 0 && temp_b->cost_b > 0) || (temp_b->cost_a < 0
				&& temp_b->cost_b < 0))
			cost = max_abs(temp_b->cost_a, temp_b->cost_b);
		else
			cost = ft_abs(temp_b->cost_a) + ft_abs(temp_b->cost_b);
		if (lowest_cost > cost)
		{
			lowest_cost = cost;
			*cost_a = temp_b->cost_a;
			*cost_b = temp_b->cost_b;
		}
		temp_b = temp_b->next;
	}
}
