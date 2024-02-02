#include "push_swap.h"

void	find_target_position(t_stack **a, t_stack **b)
{
	int		found;
	int		target_pos;
	int		target_index;
	t_stack	*temp_a;
	t_stack	*temp_b;

	temp_b = *b;
	while (temp_b)
	{
		found = 0;
		target_pos = 0;
		target_index = INT_MAX;
		temp_a = *a;
		while (temp_a)
		{
			if (temp_a->index > temp_b->index && temp_a->index < target_index)
			{
				target_pos = temp_a->pos;
				target_index = temp_a->index;
				temp_b->target_pos = target_pos;
				found = 1;
			}
			temp_a = temp_a->next;
		}
		if (found == 0)
		{
			target_pos = -1;
			target_index = INT_MAX;
			temp_a = *a;
			while (temp_a)
			{
				if (temp_a->index < temp_b->index
					&& temp_a->index < target_index)
				{
					target_pos = temp_a->pos;
					target_index = temp_a->index;
					temp_b->target_pos = target_pos;
				}
				temp_a = temp_a->next;
			}
		}
		temp_b = temp_b->next;
	}
}

void	find_position(t_stack **head)
{
	int		position;
	t_stack	*temp;

	position = 0;
	temp = *head;
	while (temp)
	{
		temp->pos = position;
		temp = temp->next;
		position++;
	}
}

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

void	move(t_stack **a, t_stack **b, int cost_a, int cost_b)
{
	while (cost_a < 0 && cost_b < 0)
	{
		rrr(a, b);
		cost_a++;
		cost_b++;
	}
	while (cost_a > 0 && cost_b > 0)
	{
		rr(a, b);
		cost_a--;
		cost_b--;
	}
	while (cost_a > 0 || cost_b > 0)
	{
		if (cost_a > 0)
		{
			ra(a);
			cost_a--;
		}
		else if (cost_b > 0)
		{
			rb(b);
			cost_b--;
		}
	}
	while (cost_a < 0 || cost_b < 0)
	{
		if (cost_a < 0)
		{
			rra(a);
			cost_a++;
		}
		else if (cost_b < 0)
		{
			rrb(b);
			cost_b++;
		}
	}
	pa(b, a);
}

int find_first_index_pos(t_stack **stack)
{
	t_stack *temp;
	int	first_index_pos;

	first_index_pos = -1;
	find_position(stack);
	temp = *stack;
	while(temp)
	{
		if(temp->index == 1)
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

void	sort_stack(t_stack **a, t_stack **b)
{
	int	len;
	int	count;
	int	middle_index;
	int	cost_a;
	int	cost_b;

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
	// ft_printf("A\n");
	// print_stack(*a);
	// ft_printf("\n\n");
	// ft_printf("B\n");
	// print_stack(*b);
}
