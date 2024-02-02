#include "push_swap.h"
#include <stdio.h>

void	fill_with_index(t_stack *a, t_tree_node *root)
{
	while (a)
	{
		a->index = binary_tree_search(root, a->value);
		if (a->index == -1)
			message_exit(4);
		a = a->next;
	}
}

void	check_if_sorted(t_stack *a)
{
	int	i;

	i = 1;
	while (a)
	{
		if (a->index != i)
			return ;
		a = a->next;
		i++;
	}
	message_exit(4);
}

void	choose_sort(t_stack **a, t_stack **b)
{
	int	len_a;

	len_a = ft_stack_size(*a);
	if (len_a == 2)
		sort_two(a);
	else if (len_a == 3)
		sort_three(a);
	else if (len_a > 3)
		sort_stack(a, b);
	exit(EXIT_SUCCESS);
}

int	main(int argc, char *argv[])
{
	t_stack		*a;
	t_stack		*b;
	t_tree_node	*root;

	a = NULL;
	b = NULL;
	check_args(argv, argc);
	root = build_binary_tree(argv, argc);
	a = fill_stack_a(argv, argc);
	fill_with_index(a, root);
	check_if_sorted(a);
	choose_sort(&a, &b);

	return (0);
}
