#include "push_swap.h"
#include <stdio.h>

void	message_exit(int message)
{
	if (message == 1)
	{
		printf("Some arguments are not integers.\n");
		exit(EXIT_FAILURE);
	}
    else if(message == 2)
	{
		printf("Some arguments are bigger than an integer.\n");
		exit(EXIT_FAILURE);
	}
    else if(message == 3)
	{
		printf("There are duplicates.\n");
		exit(EXIT_FAILURE);
	}
	else if(message == 3)
	{
		printf("Value not found.\n");
		exit(EXIT_FAILURE);
	}
	else if(message == 4)
	{
		printf("Stack A is already sorted.\n");
		exit(EXIT_FAILURE);
	}
	else if(message == 5)
	{
		printf("Number of arguments is invalid. Should have at least 2 elements to be sorted.\n");
		exit(EXIT_FAILURE);
	}
}
