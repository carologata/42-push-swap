/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cogata <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 12:18:06 by cogata            #+#    #+#             */
/*   Updated: 2024/02/19 12:18:08 by cogata           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_if_sorted(t_stack *a, t_list **mem)
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
	message_exit(NULL, mem);
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
}

char	**deal_with_one_str(int *i, char **argv, t_list **mem)
{
	*i = 0;
	if (*argv[1] == '\0')
		message_exit("Error\n", NULL);
	argv = ft_split(argv[1], ' ');
	if (!argv)
		message_exit("Error\n", NULL);
	garbage_collector(argv, mem, POINTER_TO_POINTER);
	return (argv);
}

int	main(int argc, char *argv[])
{
	int			i;
	t_stack		*a;
	t_stack		*b;
	t_tree_node	*root;
	t_list		*mem;

	i = 1;
	a = NULL;
	b = NULL;
	mem = NULL;
	if (argc < 2)
		message_exit(NULL, NULL);
	if (argc == 2)
		argv = deal_with_one_str(&i, argv, &mem);
	root = build_binary_tree(argv, i, &mem);
	a = fill_stack_a(argv, i, &mem);
	fill_with_index(a, root, &mem);
	check_if_sorted(a, &mem);
	choose_sort(&a, &b);
	if (mem)
		ft_lstclear(&mem, free);
	return (0);
}
