/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cogata <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 16:26:08 by cogata            #+#    #+#             */
/*   Updated: 2024/02/06 16:26:12 by cogata           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include "../libft/libft.h"
# include <limits.h>
# include <stdlib.h>

typedef struct s_tree_node
{
	int					data;
	int					index;
	struct s_tree_node	*right;
	struct s_tree_node	*left;
}						t_tree_node;

typedef struct s_stack
{
	int					value;
	int					index;
	int					pos;
	int					target_pos;
	int					cost_a;
	int					cost_b;
	struct s_stack		*next;
}						t_stack;

int						check_is_number(char *arg);
int						check_arg(t_tree_node *root, char *arg);

int						binary_tree_search(t_tree_node *root, int data);
void					index_tree_node(t_tree_node **root);
void					add_tree_node(t_tree_node **root, int data);
t_tree_node				*build_binary_tree(char *argv[], int i);

t_stack					*ft_stack_new(int value);
void					ft_stack_add_back(t_stack **head, t_stack *new);
int						ft_stack_size(t_stack *stack);
t_stack					*ft_stack_last(t_stack *stack);
t_stack					*ft_stack_penultime(t_stack *stack);

t_stack					*fill_stack_a(char *argv[], int i);
void					fill_with_index(t_stack *a, t_tree_node *root);
void					read_move(t_stack **a, t_stack **b);
void					check_if_sorted(t_stack *a, t_stack *b);

void					ss(t_stack **a, t_stack **b);
void					rr(t_stack **a, t_stack **b);
void					rrr(t_stack **a, t_stack **b);
void					move(char *movement, t_stack **a, t_stack **b);

void					swap(t_stack **head);
void					push(t_stack **src, t_stack **dest);
void					rotate(t_stack **head);
void					reverse_rotate(t_stack **head);

long					ft_long_atoi(const char *nptr);
int						ft_abs(int value);
int						max_abs(int value1, int value2);
void					message_exit(char *message);

#endif
