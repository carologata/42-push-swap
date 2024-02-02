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

void	check_args(char *argv[], int argc)
{
	int		i;
	int		is_number;
	long	number;
	int		comparison[argc - 1];

	if(argc < 3)
		message_exit(5);
	i = 1;
	while (i < argc)
	{
		is_number = check_is_number(argv[i]);
		if (is_number == -1)
			message_exit(1);
		number = ft_long_atoi(argv[i]);
		if (number > 2147483647 || number < -2147483648)
			message_exit(2);
		comparison[i - 1] = number;
		if(check_if_exist(number, comparison, (i - 1)) == -1)
			message_exit(3);
		i++;
	}
}