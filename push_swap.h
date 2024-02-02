
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
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
int						check_if_exist(int number, int *comparison, int index);
void					check_args(char *argv[], int argc);

t_tree_node				*build_binary_tree(char *argv[], int argc);
void					add_tree_node(t_tree_node **root, int data);
void					index_tree_node(t_tree_node **root);
int						binary_tree_search(t_tree_node *root, int data);

t_stack					*ft_stack_new(int value);
t_stack					*ft_stack_last(t_stack *stack);
void					ft_stack_add_back(t_stack **stack, t_stack *new);
t_stack					*fill_stack_a(char *argv[], int argc);
int						ft_stack_size(t_stack *stack);
t_stack					*ft_stack_penultime(t_stack *stack);

void					fill_with_index(t_stack *a, t_tree_node *root);
void					check_if_sorted(t_stack *a);
void					choose_sort(t_stack **a, t_stack **b);

void					sort_two(t_stack **a);
void					sort_three(t_stack **a);
void					sort_stack(t_stack **a, t_stack **b);

void					find_target_position(t_stack **a, t_stack **b);
void					find_position(t_stack **head);
void					cost_calculate(t_stack *a, t_stack *b);
void					find_lowest_cost(t_stack **b, int *cost_a, int *cost_b);
void					move(t_stack **a, t_stack **b, int cost_a, int cost_b);

void					swap(t_stack **head);
void					push(t_stack **src, t_stack **dest);
void					rotate(t_stack **head);
void					reverse_rotate(t_stack **head);

void					sa(t_stack **a);
void					sb(t_stack **b);
void					ss(t_stack **a, t_stack **b);
void					pa(t_stack **b, t_stack **a);
void					pb(t_stack **a, t_stack **b);
void					ra(t_stack **a);
void					rb(t_stack **b);
void					rr(t_stack **a, t_stack **b);
void					rra(t_stack **a);
void					rrb(t_stack **b);
void					rrr(t_stack **a, t_stack **b);

void					message_exit(int message);

long					ft_long_atoi(const char *nptr);
void					print_stack(t_stack *stack);
int						ft_abs(int value);
int						max_abs(int value1, int value2);

#endif