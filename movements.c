#include "push_swap.h"

void	swap(t_stack **head)
{
	t_stack *temp;

	temp = (*head)->next;
	(*head)->next = (*head)->next->next;
	temp->next = *head;
	*head = temp;
}

void push(t_stack **src, t_stack **dest)
{
    t_stack *temp;

    temp = (*src)->next;
    if(*dest != NULL)
    {
        (*src)->next = *dest; 
        *dest = *src;
    }
    else
    {
        *dest = *src;
        (*dest)->next = NULL;
    }
    *src = temp;
}

void rotate(t_stack **head)
{
    t_stack *temp;
    t_stack *last;

    temp = (*head)->next;
    last = ft_stack_last(*head);
    last->next = *head;
    (*head)->next = NULL;
    *head = temp;
}

void reverse_rotate(t_stack **head)
{
    t_stack *penultime;
    t_stack *last;

    penultime = ft_stack_penultime(*head);
    last = ft_stack_last(*head);
    last->next = *head;
    *head = last;
    penultime->next = NULL;
}