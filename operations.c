#include "push_swap.h"

void sa(t_stack **a)
{
    ft_printf("sa\n");
    swap(a);
}

void sb(t_stack **b)
{
    ft_printf("sb\n");
    swap(b);
}

void ss(t_stack **a, t_stack **b)
{
    ft_printf("ss\n");
    swap(a);
    swap(b);
}

void pa(t_stack **b, t_stack **a)
{
    ft_printf("pa\n");
    push(b, a);
}

void pb(t_stack **a, t_stack **b)
{
    ft_printf("pb\n");
    push(a, b);
}

void ra(t_stack **a)
{
    ft_printf("ra\n");
    rotate(a);
}

void rb(t_stack **b)
{
    ft_printf("rb\n");
    rotate(b);
}

void rr(t_stack **a, t_stack **b)
{
    ft_printf("rr\n");
    rotate(a);
    rotate(b);
}

void rra(t_stack **a)
{
    ft_printf("rra\n");
    reverse_rotate(a);
}

void rrb(t_stack **b)
{
    ft_printf("rrb\n");
    reverse_rotate(b);
}

void rrr(t_stack **a, t_stack **b)
{
    ft_printf("rrr\n");
    reverse_rotate(a);
    reverse_rotate(b);
}