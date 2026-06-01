/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caida-si <caida-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 15:28:11 by caida-si          #+#    #+#             */
/*   Updated: 2025/10/06 13:17:27 by caida-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static long	ft_atol(const char *s)
{
	long	result;
	int		sign;
	int		digit;

	result = 0;
	sign = 1;
	while (*s == ' ' || *s == '\t' || *s == '\n'
		|| *s == '\r' || *s == '\f' || *s == '\v')
		s++;
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			sign = -sign;
		s++;
	}
	while (ft_isdigit(*s))
	{
		digit = *s++ - '0';
		if (sign == 1 && (result > (LONG_MAX - digit) / 10))
			return (LONG_MAX);
		if (sign == -1 && (result > (LONG_MAX - digit) / 10))
			return (LONG_MIN);
		result = result * 10 + digit;
	}
	return (result * sign);
}

static void	append_node(t_stack_node **stack, int n)
{
	t_stack_node	*node;
	t_stack_node	*last_node;

	if (!stack)
		return ;
	node = malloc(sizeof(t_stack_node));
	if (!node)
		return ;
	node->next = NULL;
	node->nbr = n;
	if (!(*stack))
	{
		*stack = node;
		node->prev = NULL;
	}
	else
	{
		last_node = find_last(*stack);
		last_node->next = node;
		node->prev = last_node;
	}
}

static void	handle_error(t_stack_node **a, char **split)
{
	if (split)
		free_errors_split(a, split);
	else
		free_errors(a);
}

void	init_stack_a(t_stack_node **a, char **av, char **split)
{
	long	n;
	int		i;

	i = 0;
	while (av[i])
	{
		if (error_syntax(av[i]))
			handle_error(a, split);
		n = ft_atol(av[i]);
		if (n > INT_MAX || n < INT_MIN)
			handle_error(a, split);
		if (error_duplicate(*a, (int)n))
			handle_error(a, split);
		append_node(a, (int)n);
		i++;
	}
}

void	prep_for_push(t_stack_node **stack,
					t_stack_node *top_node,
					char stack_name)
{
	while (*stack != top_node)
	{
		if (stack_name == 'a')
		{
			if (top_node->above_median)
				ra(stack, false);
			else
				rra(stack, false);
		}
		else if (stack_name == 'b')
		{
			if (top_node->above_median)
				rb(stack, false);
			else
				rrb(stack, false);
		}
	}
}
