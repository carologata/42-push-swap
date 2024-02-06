#include "push_swap.h"

int	find_top_closest_target(t_stack *temp_a, t_stack *temp_b)
{
	int	found;
	int	target_pos;
	int	target_index;

	found = 0;
	target_pos = 0;
	target_index = INT_MAX;
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
	return (found);
}

void	find_bottom_closest_target(t_stack *temp_a, t_stack *temp_b)
{
	int	target_pos;
	int	target_index;

	target_pos = -1;
	target_index = INT_MAX;
	while (temp_a)
	{
		if (temp_a->index < temp_b->index && temp_a->index < target_index)
		{
			target_pos = temp_a->pos;
			target_index = temp_a->index;
			temp_b->target_pos = target_pos;
		}
		temp_a = temp_a->next;
	}
}

void	find_target_position(t_stack **a, t_stack **b)
{
	int		found;
	int		target_pos;
	int		target_index;
	t_stack	*temp_b;

	temp_b = *b;
	while (temp_b)
	{
		target_pos = 0;
		target_index = INT_MAX;
		found = find_top_closest_target(*a, temp_b);
		if (found == 0)
			find_bottom_closest_target(*a, temp_b);
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
