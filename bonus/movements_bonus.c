/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cogata <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 16:25:38 by cogata            #+#    #+#             */
/*   Updated: 2024/02/06 16:25:40 by cogata           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	swap(t_stack **head)
{
	t_stack	*temp;

	if (*head == NULL)
		return ;
	else if ((*head)->next == NULL)
		return ;
	temp = (*head)->next;
	(*head)->next = (*head)->next->next;
	temp->next = *head;
	*head = temp;
}

void	push(t_stack **src, t_stack **dest)
{
	t_stack	*temp;

	if (*src == NULL)
		return ;
	temp = (*src)->next;
	if (*dest != NULL)
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

void	rotate(t_stack **head)
{
	t_stack	*temp;
	t_stack	*last;

	if (*head == NULL)
		return ;
	else if ((*head)->next == NULL)
		return ;
	temp = (*head)->next;
	last = ft_stack_last(*head);
	last->next = *head;
	(*head)->next = NULL;
	*head = temp;
}

void	reverse_rotate(t_stack **head)
{
	t_stack	*penultime;
	t_stack	*last;

	if (*head == NULL)
		return ;
	else if ((*head)->next == NULL)
		return ;
	penultime = ft_stack_penultime(*head);
	last = ft_stack_last(*head);
	last->next = *head;
	*head = last;
	penultime->next = NULL;
}
