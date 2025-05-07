/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stackfish.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcygan <mcygan@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 17:07:47 by mcygan            #+#    #+#             */
/*   Updated: 2024/05/25 19:14:41 by mcygan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	set_cost(t_node *elem, int i, int n, char stack)
{
	if (i < (n / 2) + 1)
	{
		elem->cost = i;
		if (stack == 'a')
			elem->func = ra;
		else
			elem->func = rb;
	}
	else
	{
		elem->cost = i % ((n / 2) + (n % 2)) - (n / 2);
		if (stack == 'a')
			elem->func = rra;
		else
			elem->func = rrb;
	}
	elem->opti = 0;
}

static void	init_costs(t_node **a, t_node **b)
{
	t_node	*stack;
	int		size;
	int		i;

	stack = *a;
	size = stack_size(stack);
	i = -1;
	while (i++, stack)
	{
		stack->pos = i;
		set_cost(stack, i, size, 'a');
		stack = stack->next;
	}
	stack = *b;
	size = stack_size(stack);
	i = -1;
	while (i++, stack)
	{
		stack->pos = i;
		set_cost(stack, i, size, 'b');
		stack = stack->next;
	}
}

static void	optimize(t_node *to_insert, t_node *next_elem)
{
	if ((to_insert->cost > 0 && next_elem->cost > 0) || \
		(to_insert->cost < 0 && next_elem->cost < 0))
	{
		if ((ft_abs(to_insert->cost) > ft_abs(next_elem->cost)))
		{
			to_insert->opti = next_elem->cost;
			to_insert->cost -= next_elem->cost;
			next_elem->cost = 0;
		}
		else
		{
			to_insert->opti = to_insert->cost;
			next_elem->cost -= to_insert->cost;
			to_insert->cost = 0;
		}
	}
}

void	stackfish(t_node **a, t_node **b)
{
	t_node	*to_insert;
	t_node	*next_elem;
	void	(*func1)(t_node **stack);
	void	(*func2)(t_node **a, t_node **b);

	init_costs(a, b);
	to_insert = find_val_to_insert(a, b);
	next_elem = find_next(a, to_insert->val);
	optimize(to_insert, next_elem);
	func1 = to_insert->func;
	to_insert->cost = ft_abs(to_insert->cost);
	while (to_insert->cost--)
		func1(b);
	func1 = next_elem->func;
	next_elem->cost = ft_abs(next_elem->cost);
	while (next_elem->cost--)
		func1(a);
	if (to_insert->opti > 0)
		func2 = rr;
	else
		func2 = rrr;
	to_insert->opti = ft_abs(to_insert->opti);
	while (to_insert->opti--)
		func2(a, b);
	pa(a, b);
}
