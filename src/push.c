/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcygan <mcygan@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 14:50:49 by mcygan            #+#    #+#             */
/*   Updated: 2024/05/27 09:18:22 by mcygan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	push(t_node **dst, t_node **src)
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

void	pa(t_node **a, t_node **b)
{
	push(a, b);
	write(1, "pa\n", 3);
}

void	pb(t_node **a, t_node **b)
{
	push(b, a);
	write(1, "pb\n", 3);
}
