/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stackfish_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcygan <mcygan@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 19:09:28 by mcygan            #+#    #+#             */
/*   Updated: 2024/05/26 11:47:05 by mcygan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	ft_abs(int nb)
{
	if (nb < 0)
		nb = -nb;
	return (nb);
}

t_node	*find_next(t_node **a, int elem)
{
	t_node	*min;
	t_node	*stack;

	stack = *a;
	if (elem < stack->val && elem > get_tail(stack)->val)
		return (*a);
	min = stack;
	while (stack->next)
	{
		if (elem > stack->val && elem < stack->next->val)
			return (stack->next);
		if (min->val > stack->next->val)
			min = stack->next;
		stack = stack->next;
	}
	return (min);
}

static int	calc_optimized_cost(t_node *to_insert, t_node *next_elem)
{
	if ((to_insert->cost > 0 && next_elem->cost > 0) || \
		(to_insert->cost < 0 && next_elem->cost < 0))
	{
		if ((ft_abs(to_insert->cost) > ft_abs(next_elem->cost)))
			return (ft_abs(to_insert->cost));
		else
			return (ft_abs(next_elem->cost));
	}
	return (ft_abs(to_insert->cost) + ft_abs(next_elem->cost));
}

t_node	*find_val_to_insert(t_node **a, t_node **b)
{
	t_node	*best_node;
	int		lowest;
	int		score;
	t_node	*stack;

	stack = *b;
	best_node = stack;
	lowest = calc_optimized_cost(stack, find_next(a, stack->val));
	stack = stack->next;
	while (stack)
	{
		score = calc_optimized_cost(stack, find_next(a, stack->val));
		if (score < lowest)
		{
			best_node = stack;
			lowest = score;
		}
		stack = stack->next;
	}
	return (best_node);
}
