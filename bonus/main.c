/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cogata <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 12:18:18 by cogata            #+#    #+#             */
/*   Updated: 2024/02/19 12:18:20 by cogata           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	read_move(t_stack **a, t_stack **b, t_list **mem)
{
	char	*line;

	line = get_next_line(0);
	if (line)
		garbage_collector(line, mem, POINTER);
	while (line != NULL)
	{
		move(line, a, b, mem);
		line = get_next_line(0);
		if (line)
			garbage_collector(line, mem, POINTER);
	}
}

void	check_if_sorted(t_stack *a, t_stack *b, t_list **mem)
{
	int	i;

	i = 1;
	while (a)
	{
		if (a->index != i)
			message_exit("KO\n", mem);
		a = a->next;
		i++;
	}
	if (b)
		message_exit("KO\n", mem);
	message_exit("OK\n", mem);
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
	read_move(&a, &b, &mem);
	check_if_sorted(a, b, &mem);
	if (mem)
		ft_lstclear(&mem, free);
	return (0);
}
