/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_tree_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cogata <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 16:25:07 by cogata            #+#    #+#             */
/*   Updated: 2024/02/06 16:25:08 by cogata           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	binary_tree_search(t_tree_node *root, int data)
{
	if (root == NULL)
		return (-1);
	else if (root->data == data)
		return (root->index);
	else if (root->data < data)
		return (binary_tree_search(root->right, data));
	else if (root->data > data)
		return (binary_tree_search(root->left, data));
	else
		return (-1);
}

void	index_tree_node(t_tree_node **root)
{
	static int	index = 1;

	if ((*root)->left)
		index_tree_node(&(*root)->left);
	if (*root)
	{
		(*root)->index = index;
		index++;
	}
	if ((*root)->right)
		index_tree_node(&(*root)->right);
}

void	add_tree_node(t_tree_node **root, int data, t_list **mem)
{
	if (*root == NULL)
	{
		*root = malloc(sizeof(t_tree_node));
		garbage_collector(*root, mem, POINTER);
		(*root)->data = data;
		(*root)->index = 0;
		(*root)->right = NULL;
		(*root)->left = NULL;
	}
	else if (data > (*root)->data)
		add_tree_node(&(*root)->right, data, mem);
	else if (data < (*root)->data)
		add_tree_node(&(*root)->left, data, mem);
}

t_tree_node	*build_binary_tree(char *argv[], int i, t_list **mem)
{
	int			data;
	t_tree_node	*root;

	root = NULL;
	while (argv[i])
	{
		data = check_arg(root, argv[i], mem);
		add_tree_node(&root, data, mem);
		i++;
	}
	index_tree_node(&root);
	return (root);
}
