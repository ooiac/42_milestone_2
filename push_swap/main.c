/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caida-si <caida-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 13:49:47 by caida-si          #+#    #+#             */
/*   Updated: 2025/10/06 13:17:21 by caida-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	handle_args(int ac, char **av, t_stack_node **a, char ***split_av)
{
	if (ac == 2)
	{
		*split_av = ft_split_ps(av[1], ' ');
		init_stack_a(a, *split_av, *split_av);
	}
	else
		init_stack_a(a, av + 1, NULL);
}

static void	sort_stack(t_stack_node **a, t_stack_node **b)
{
	if (stack_len(*a) == 2)
		sa(a, false);
	else if (stack_len(*a) == 3)
		sort_three(a);
	else
		sort_stacks(a, b);
}

int	main(int ac, char **av)
{
	t_stack_node	*a;
	t_stack_node	*b;
	char			**split_av;

	a = NULL;
	b = NULL;
	split_av = NULL;
	if (ac == 1 || (ac == 2 && !av[1][0]))
		return (0);
	handle_args(ac, av, &a, &split_av);
	if (!stack_sorted(a))
		sort_stack(&a, &b);
	free_stack(&a);
	if (split_av)
		free_split(split_av);
	return (0);
}
