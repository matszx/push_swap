/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcygan <mcygan@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 12:59:35 by mcygan            #+#    #+#             */
/*   Updated: 2024/05/27 10:37:55 by mcygan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap_bonus.h"

long	ft_atol(const char *s)
{
	long	res;
	int		sign;
	long	last;

	res = 0;
	sign = 1;
	while (*s == '+' || *s == '-')
	{
		if (*s++ == '-')
			sign *= -1;
	}
	while (*s >= '0' && *s <= '9')
	{
		last = res;
		res = res * 10 + (*s++ - '0');
		if (res < last)
			return (LONG_MAX);
	}
	return (res * sign);
}

int	stack_size(t_node *stack)
{
	int	len;

	if (!stack)
		return (0);
	len = 0;
	while (len++, stack->next)
		stack = stack->next;
	return (len);
}

int	is_sorted(t_node *stack)
{
	while (stack && stack->next)
	{
		if (stack->val > stack->next->val)
			return (0);
		stack = stack->next;
	}
	return (1);
}

t_node	*get_tail(t_node *stack)
{
	while (stack->next)
		stack = stack->next;
	return (stack);
}

void	free_stacks(t_node *a, t_node *b)
{
	if (a)
	{
		while (a->next)
		{
			a = a->next;
			free(a->prev);
		}
		free(a);
	}
	if (b)
	{
		while (b->next)
		{
			b = b->next;
			free(b->prev);
		}
		free(b);
	}
}
