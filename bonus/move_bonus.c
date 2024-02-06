/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cogata <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 16:25:34 by cogata            #+#    #+#             */
/*   Updated: 2024/02/06 16:25:36 by cogata           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ss(t_stack **a, t_stack **b)
{
	swap(a);
	swap(b);
}

void	rr(t_stack **a, t_stack **b)
{
	rotate(a);
	rotate(b);
}

void	rrr(t_stack **a, t_stack **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
}

void	move(char *movement, t_stack **a, t_stack **b)
{
	if (ft_strncmp(movement, "sa\n", 3) == 0)
		swap(a);
	else if (ft_strncmp(movement, "sb\n", 3) == 0)
		swap(b);
	else if (ft_strncmp(movement, "ss\n", 3) == 0)
		ss(a, b);
	else if (ft_strncmp(movement, "ra\n", 3) == 0)
		rotate(a);
	else if (ft_strncmp(movement, "rb\n", 3) == 0)
		rotate(b);
	else if (ft_strncmp(movement, "rr\n", 3) == 0)
		rr(a, b);
	else if (ft_strncmp(movement, "rra\n", 4) == 0)
		reverse_rotate(a);
	else if (ft_strncmp(movement, "rrb\n", 4) == 0)
		reverse_rotate(b);
	else if (ft_strncmp(movement, "rrr\n", 4) == 0)
		rrr(a, b);
	else if (ft_strncmp(movement, "pa\n", 3) == 0)
		push(b, a);
	else if (ft_strncmp(movement, "pb\n", 3) == 0)
		push(a, b);
	else
		message_exit("Error");
}
