/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcygan <mcygan@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 09:30:56 by mcygan            #+#    #+#             */
/*   Updated: 2024/05/27 10:33:38 by mcygan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap_bonus.h"

void	swap(t_node **stack)
{
	if (!stack || !*stack || !(*stack)->next)
		return ;
	*stack = (*stack)->next;
	(*stack)->prev->prev = *stack;
	(*stack)->prev->next = (*stack)->next;
	if ((*stack)->next)
		(*stack)->next->prev = (*stack)->prev;
	(*stack)->next = (*stack)->prev;
	(*stack)->prev = NULL;
}

void	push(t_node **dst, t_node **src)
{
	t_node	*elem;

	if (!*src)
		return ;
	elem = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	if (*dst)
	{
		elem->next = *dst;
		elem->next->prev = elem;
		*dst = elem;
	}
	else
	{
		*dst = elem;
		elem->next = NULL;
	}
}

void	rotate(t_node **stack)
{
	t_node	*tail;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	tail = get_tail(*stack);
	tail->next = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	tail->next->prev = tail;
	tail->next->next = NULL;
}

void	rrotate(t_node **stack)
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
