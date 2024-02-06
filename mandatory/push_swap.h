
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

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

t_tree_node				*build_binary_tree(char *argv[], int i);
void					add_tree_node(t_tree_node **root, int data);
void					index_tree_node(t_tree_node **root);
int						binary_tree_search(t_tree_node *root, int data);

t_stack					*ft_stack_new(int value);
void					ft_stack_add_back(t_stack **head, t_stack *new);
int						ft_stack_size(t_stack *stack);
t_stack					*ft_stack_last(t_stack *stack);
t_stack					*ft_stack_penultime(t_stack *stack);

t_stack					*fill_stack_a(char *argv[], int i);
void					fill_with_index(t_stack *a, t_tree_node *root);
void					check_if_sorted(t_stack *a);
void					choose_sort(t_stack **a, t_stack **b);

int						find_top_closest_target(t_stack *temp_a,
							t_stack *temp_b);
void					find_bottom_closest_target(t_stack *temp_a,
							t_stack *temp_b);
void					find_target_position(t_stack **a, t_stack **b);
void					find_position(t_stack **head);

void					cost_calculate(t_stack *a, t_stack *b);
void					find_lowest_cost(t_stack **b, int *cost_a, int *cost_b);
void					costs_lower_than_zero(t_stack **a, t_stack **b,
							int *cost_a, int *cost_b);
void					costs_higher_than_zero(t_stack **a, t_stack **b,
							int *cost_a, int *cost_b);
void					cost_a_or_b_higher_than_zero(t_stack **a, t_stack **b,
							int *cost_a, int *cost_b);
void					cost_a_or_b_lower_than_zero(t_stack **a, t_stack **b,
							int *cost_a, int *cost_b);
void					move(t_stack **a, t_stack **b, int cost_a, int cost_b);

void					sort_two(t_stack **a);
void					ind_big_and_middle(t_stack *a, int *big, int *middle);
void					sort_three(t_stack **a);

int						find_first_index_pos(t_stack **stack);
void					move_if_necessary(t_stack **head);
void					do_pb_or_ra(t_stack **a, t_stack **b);
void					sort_stack(t_stack **a, t_stack **b);

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

long					ft_long_atoi(const char *nptr);
int						ft_abs(int value);
int						max_abs(int value1, int value2);
void					message_exit(char *message);

#endif