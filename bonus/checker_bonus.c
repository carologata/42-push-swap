/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cogata <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 16:25:15 by cogata            #+#    #+#             */
/*   Updated: 2024/02/06 16:25:17 by cogata           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

t_stack	*fill_stack_a(char *argv[], int i)
{
	t_stack	*a;
	t_stack	*temp;

	a = NULL;
	while (argv[i])
	{
		temp = ft_stack_new(ft_atoi(argv[i]));
		ft_stack_add_back(&a, temp);
		i++;
	}
	return (a);
}

void	fill_with_index(t_stack *a, t_tree_node *root)
{
	while (a)
	{
		a->index = binary_tree_search(root, a->value);
		if (a->index == -1)
			message_exit("Error");
		a = a->next;
	}
}

void	read_move(t_stack **a, t_stack **b)
{
	int		i;
	char	buffer[4];

	i = 0;
	while (read(1, &buffer[i], 1) == 1)
	{
		if (buffer[i] == '\n')
		{
			move(buffer, a, b);
			i = 0;
		}
		else
		{
			i++;
		}
	}
}

void	check_if_sorted(t_stack *a, t_stack *b)
{
	int	i;

	i = 1;
	while (a)
	{
		if (a->index != i)
			message_exit("KO");
		a = a->next;
		i++;
	}
	if (b)
		message_exit("KO");
	message_exit("OK");
}

int	main(int argc, char *argv[])
{
	int			i;
	t_stack		*a;
	t_stack		*b;
	t_tree_node	*root;

	a = NULL;
	b = NULL;
	i = 1;
	if (argc < 2)
		message_exit("Error");
	if (argc == 2)
	{
		i = 0;
		argv = ft_split(argv[1], ' ');
		if (argv[1] == NULL)
			message_exit("Error");
	}
	root = build_binary_tree(argv, i);
	a = fill_stack_a(argv, i);
	fill_with_index(a, root);
	read_move(&a, &b);
	check_if_sorted(a, b);
}
