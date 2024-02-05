#include "push_swap.h"

int	check_is_number(char *arg)
{
	int	i;
	int	is_number;

	i = 0;
	is_number = -1;
	if ((arg[i] == '-' || arg[i] == '+') && arg[i + 1])
	{
		i++;
	}
	while (arg[i] != '\0')
	{
		if (arg[i] >= '0' && arg[i] <= '9')
			is_number = 1;
		else
			return (-1);
		i++;
	}
	return (is_number);
}

int	check_if_exist(int number, int *comparison, int index) 
{
	int i;
	i = 0;
	while (i < index) 
	{
		if (number == *comparison) 
			return (-1);
		comparison = comparison + 1;
		i++;
	}
	return (0);
}

int	check_arg(t_tree_node *root, char *arg)
{
	int		i;
	int		is_number;
	long	number;

	i = 1;
	is_number = check_is_number(arg);
	if (is_number == -1)
		message_exit(1);
	number = ft_long_atoi(arg);
	if (number > 2147483647 || number < -2147483648)
		message_exit(2);
	if(binary_tree_search(root, number) != -1)
		message_exit(3);
	return (number);
	i++;
}
