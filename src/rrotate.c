/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcygan <mcygan@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 16:03:34 by mcygan            #+#    #+#             */
/*   Updated: 2024/05/27 09:18:32 by mcygan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	rrotate(t_node **stack)
{
	t_node	*tail;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	tail = get_tail(*stack);
	tail->next = *stack;
	tail->prev->next = NULL;
	tail->prev = NULL;
	(*stack)->prev = tail;
	*stack = tail;
}

void	rra(t_node **a)
{
	rrotate(a);
	write(1, "rra\n", 4);
}

void	rrb(t_node **b)
{
	rrotate(b);
	write(1, "rrb\n", 4);
}

void	rrr(t_node **a, t_node **b)
{
	rrotate(a);
	rrotate(b);
	write(1, "rrr\n", 4);
}
