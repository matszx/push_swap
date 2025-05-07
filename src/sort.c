/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcygan <mcygan@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 12:10:02 by mcygan            #+#    #+#             */
/*   Updated: 2024/05/26 11:50:06 by mcygan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	tiny_sort(t_node **a, t_node **b)
{
	while (stack_size(*a) > 3)
		pb(a, b);
	if (is_sorted(*a))
		return ;
	if ((*a)->idx > (*a)->next->idx && !(*a)->next->next)
		return (sa(a));
	if (((*a)->idx > (*a)->next->idx && \
		(*a)->idx < (*a)->next->next->idx)
		|| \
		((*a)->idx > (*a)->next->idx && \
		(*a)->next->idx > (*a)->next->next->idx)
		|| \
		((*a)->idx < (*a)->next->idx && \
		(*a)->idx < (*a)->next->next->idx))
		sa(a);
	if ((*a)->idx > (*a)->next->idx && \
		(*a)->idx > (*a)->next->next->idx)
		ra(a);
	if ((*a)->idx < (*a)->next->idx && \
		(*a)->idx > (*a)->next->next->idx)
		rra(a);
}

static void	push_non_lis(t_node **a, t_node **b, int n)
{
	int	i;

	i = 0;
	while (i++ < n && stack_size(*a) > 3)
	{
		if ((*a)->lis)
			ra(a);
		else
		{
			pb(a, b);
			if ((*b)->idx > n / 2)
			{
				if ((*a) && (*a)->lis && i++ < n)
					rr(a, b);
				else
					rb(b);
			}
		}
	}
}

static void	rotate_till_sorted(t_node **a, int n)
{
	void	(*func)(t_node **stack);

	if ((*a)->idx > n / 2)
		func = ra;
	else
		func = rra;
	while ((*a)->idx)
		func(a);
}

void	sort(t_node **a, t_node **b, int n)
{
	if (is_sorted(*a))
		return ;
	if (n <= 5)
		tiny_sort(a, b);
	else
	{
		longest_increasing_subsequence(*a);
		push_non_lis(a, b, n);
		if (!is_sorted(*a))
			tiny_sort(a, b);
	}
	while (*b)
		stackfish(a, b);
	rotate_till_sorted(a, n);
}
