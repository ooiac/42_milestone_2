/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caida-si <caida-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 15:25:19 by caida-si          #+#    #+#             */
/*   Updated: 2025/10/06 13:17:24 by caida-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <limits.h>
# include <unistd.h>
# include "libft/libft.h"
# include "ft_printf/ft_printf.h"

typedef struct s_stack_node
{
	int					nbr;
	int					index;
	int					push_cost;
	bool				above_median;
	bool				cheapest;
	struct s_stack_node	*target_node;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}	t_stack_node;

//Handle errors
void			free_errors(t_stack_node **a);
void			free_errors_split(t_stack_node **a, char **split);
bool			error_syntax(char *str_n);
bool			error_duplicate(t_stack_node *a, int n);
void			free_stack(t_stack_node **stack);

//Stack initiation
void			init_stack_a(t_stack_node **a, char **av, char **split);
void			prep_for_push(t_stack_node **stack, t_stack_node *top_node,
					char stack_name);

//Nodes initiation
void			current_index(t_stack_node *stack);
void			set_cheapest(t_stack_node *stack);
void			init_nodes_a(t_stack_node *a, t_stack_node *b);
void			init_nodes_b(t_stack_node *a, t_stack_node *b);

//Stack utils
bool			stack_sorted(t_stack_node *stack);
t_stack_node	*find_min(t_stack_node *stack);
t_stack_node	*find_max(t_stack_node *stack);
t_stack_node	*find_last(t_stack_node *stack);
t_stack_node	*get_cheapest(t_stack_node *stack);
int				stack_len(t_stack_node *stack);

//Commands
void			sa(t_stack_node **a, bool print);
void			sb(t_stack_node **b, bool print);
void			ss(t_stack_node **a, t_stack_node **b, bool print);
void			ra(t_stack_node **a, bool print);
void			rb(t_stack_node **b, bool print);
void			rr(t_stack_node **a, t_stack_node **b, bool print);
void			rra(t_stack_node **a, bool print);
void			rrb(t_stack_node **b, bool print);
void			rrr(t_stack_node **a, t_stack_node **b, bool print);
void			pa(t_stack_node **a, t_stack_node **b, bool print);
void			pb(t_stack_node **b, t_stack_node **a, bool print);
void			rotate(t_stack_node **stack);
void			rev_rotate(t_stack_node **stack);
void			swap(t_stack_node **head);
void			push(t_stack_node **dst, t_stack_node **src);
void			rotate_both(t_stack_node **a, t_stack_node **b,
					t_stack_node *cheapest_node);
void			rev_rotate_both(t_stack_node **a, t_stack_node **b,
					t_stack_node *cheapest_node);

//Algorithms
void			sort_three(t_stack_node **a);
void			sort_stacks(t_stack_node **a, t_stack_node **b);

//Utils
char			**ft_split_ps(char *s, char c);
void			free_split(char **split);

#endif