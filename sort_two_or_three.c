#include "push_swap.h"
#include <stdio.h>

void	sort_two(t_stack **a)
{
	printf("sa\n");
	swap(a);
}

void	find_big_and_middle(t_stack *a, int *big, int *middle)
{
	t_stack	*temp;

	temp = a;
	*big = temp->index;
	while (temp)
	{
		if (temp->index > *big)
			*big = temp->index;
		else
			*middle = temp->index;
		temp = temp->next;
	}
	temp = a;
	while (temp)
	{
		if (temp->index > *middle && temp->index != *big)
			*middle = temp->index;
		temp = temp->next;
	}
}

void	sort_three(t_stack **a)
{
	int		big;
	int		middle;

	find_big_and_middle(*a, &big, &middle);
	if ((*a)->index == big)
		ra(a);
	else if ((*a)->next->index == big)
		rra(a);
	if ((*a)->index == middle)
		sa(a);
}
