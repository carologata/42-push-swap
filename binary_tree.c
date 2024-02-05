#include "push_swap.h"

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
	static int index = 1;

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

void	add_tree_node(t_tree_node **root, int data)
{
	if (*root == NULL)
	{
		*root = malloc(sizeof(t_tree_node));
		(*root)->data = data;
		(*root)->right = NULL;
		(*root)->left = NULL;
	}
	else if (data > (*root)->data)
		add_tree_node(&(*root)->right, data);
	else if (data < (*root)->data)
		add_tree_node(&(*root)->left, data);
}

t_tree_node	*build_binary_tree(char *argv[], int i)
{
	int			data;
	t_tree_node	*root;

	root = NULL;
	while (argv[i])
	{
		data = check_arg(root, argv[i]);
		add_tree_node(&root, data);
		i++;
	}
	index_tree_node(&root);
	return (root);
}
