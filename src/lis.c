/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcygan <mcygan@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 18:37:14 by mcygan            #+#    #+#             */
/*   Updated: 2024/04/20 15:54:41 by mcygan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	lis_init_vectors(t_node *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		stack->pos = i++;
		stack->d_val = 1;
		stack->p_val = -1;
		stack->lis = 0;
		stack = stack->next;
	}
}

static void	lis_set_vectors(t_node *stack)
{
	t_node	*head;
	t_node	*substack;

	head = stack;
	while (stack)
	{
		substack = head;
		while (substack != stack)
		{
			if (substack->idx < stack->idx \
			&& stack->d_val < substack->d_val + 1)
			{
				stack->d_val = substack->d_val + 1;
				stack->p_val = substack->pos;
			}
			substack = substack->next;
		}
		stack = stack->next;
	}
}

static void	lis_flag_members(t_node *stack)
{
	t_node	*d_max;
	int		index;

	d_max = stack;
	while (stack)
	{
		if (d_max->d_val < stack->d_val)
			d_max = stack;
		stack = stack->next;
	}
	while (d_max)
	{
		d_max->lis = 1;
		index = d_max->p_val;
		while (d_max->pos > index + 1)
			d_max = d_max->prev;
		d_max = d_max->prev;
	}
}

void	longest_increasing_subsequence(t_node *stack)
{
	lis_init_vectors(stack);
	lis_set_vectors(stack);
	lis_flag_members(stack);
}
