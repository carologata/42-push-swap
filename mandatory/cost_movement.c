/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_movement.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cogata <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 16:19:34 by cogata            #+#    #+#             */
/*   Updated: 2024/02/06 16:19:35 by cogata           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	costs_lower_than_zero(t_stack **a, t_stack **b, int *cost_a,
		int *cost_b)
{
	rrr(a, b);
	(*cost_a)++;
	(*cost_b)++;
}

void	costs_higher_than_zero(t_stack **a, t_stack **b, int *cost_a,
		int *cost_b)
{
	rr(a, b);
	(*cost_a)--;
	(*cost_b)--;
}

void	cost_a_or_b_higher_than_zero(t_stack **a, t_stack **b, int *cost_a,
		int *cost_b)
{
	if (*cost_a > 0)
	{
		ra(a);
		(*cost_a)--;
	}
	else if (*cost_b > 0)
	{
		rb(b);
		(*cost_b)--;
	}
}

void	cost_a_or_b_lower_than_zero(t_stack **a, t_stack **b, int *cost_a,
		int *cost_b)
{
	if (*cost_a < 0)
	{
		rra(a);
		(*cost_a)++;
	}
	else if (*cost_b < 0)
	{
		rrb(b);
		(*cost_b)++;
	}
}

void	move(t_stack **a, t_stack **b, int cost_a, int cost_b)
{
	while (cost_a < 0 && cost_b < 0)
		costs_lower_than_zero(a, b, &cost_a, &cost_b);
	while (cost_a > 0 && cost_b > 0)
		costs_higher_than_zero(a, b, &cost_a, &cost_b);
	while (cost_a > 0 || cost_b > 0)
		cost_a_or_b_higher_than_zero(a, b, &cost_a, &cost_b);
	while (cost_a < 0 || cost_b < 0)
		cost_a_or_b_lower_than_zero(a, b, &cost_a, &cost_b);
	pa(b, a);
}
