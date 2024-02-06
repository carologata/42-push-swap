#include "push_swap.h"

void	rra(t_stack **a)
{
	ft_printf("rra\n");
	reverse_rotate(a);
}

void	rrb(t_stack **b)
{
	ft_printf("rrb\n");
	reverse_rotate(b);
}

void	rrr(t_stack **a, t_stack **b)
{
	ft_printf("rrr\n");
	reverse_rotate(a);
	reverse_rotate(b);
}
