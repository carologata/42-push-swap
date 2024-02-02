#include "push_swap.h"

t_stack *ft_stack_new(int value)
{
	t_stack	*new_node;

	new_node = malloc(sizeof(t_stack));
	if (new_node == NULL)
		return (NULL);
	new_node->value = value;
	new_node->index = -1;
	new_node->pos = -1;
	new_node->target_pos = -1;
	new_node->next = NULL;
	return (new_node);
}

t_stack	*ft_stack_last(t_stack *stack)
{
	t_stack	*current;

	if (stack == NULL)
		return (NULL);
	current = stack;
	while (current != NULL)
	{
		if (current->next == NULL)
			return (current);
		current = current->next;
	}
	return (NULL);
}

void	ft_stack_add_back(t_stack **head, t_stack *new)
{
	t_stack	*last;

	if (*head == NULL)
		*head = new;
	else
	{
		last = ft_stack_last(*head);
		last->next = new;
	}
}

t_stack *fill_stack_a(char *argv[], int argc)
{
	int i;
	t_stack *a;
	t_stack *temp;
	a = NULL;

	i = 1;
	while(i < argc)
	{
		temp = ft_stack_new(ft_atoi(argv[i]));
		ft_stack_add_back(&a, temp);
		i++;
	}
	return (a);
}

int	ft_stack_size(t_stack *stack)
{
	int		count;
	t_stack	*current;

	current = stack;
	count = 0;
	while (current != NULL)
	{
		current = current->next;
		count++;
	}
	return (count);
}

t_stack	*ft_stack_penultime(t_stack *stack)
{
	t_stack	*current;

	if (stack == NULL)
		return (NULL);
	current = stack;
	while (current != NULL)
	{
		if(current->next == NULL)
			return (current);
		else if (current->next->next == NULL)
			return (current);
		current = current->next;
	}
	return (NULL);
}