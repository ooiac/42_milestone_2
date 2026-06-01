/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caida-si <caida-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 13:30:00 by caida-si          #+#    #+#             */
/*   Updated: 2025/10/06 13:17:19 by caida-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_stack_node **stack)
{
	t_stack_node	*tmp;
	t_stack_node	*current;

	if (!stack)
		return ;
	current = *stack;
	while (current)
	{
		tmp = current->next;
		current->nbr = 0;
		free(current);
		current = tmp;
	}
	*stack = NULL;
}

void	free_errors(t_stack_node **a)
{
	free_stack(a);
	write(2, "Error\n", 6);
	exit(1);
}

void	free_errors_split(t_stack_node **a, char **split)
{
	free_stack(a);
	if (split)
		free_split(split);
	write(2, "Error\n", 6);
	exit(1);
}

bool	error_syntax(char *str_n)
{
	if (!(*str_n == '+' || *str_n == '-'
			|| (*str_n >= '0' && *str_n <= '9')))
		return (true);
	if ((*str_n == '+' || *str_n == '-')
		&& !(str_n[1] >= '0' && str_n[1] <= '9'))
		return (true);
	while (*++str_n)
	{
		if (!(*str_n >= '0' && *str_n <= '9'))
			return (true);
	}
	return (false);
}

bool	error_duplicate(t_stack_node *a, int n)
{
	if (!a)
		return (false);
	while (a)
	{
		if (a->nbr == n)
			return (true);
		a = a->next;
	}
	return (false);
}
