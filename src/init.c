/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcygan <mcygan@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 10:27:59 by mcygan            #+#    #+#             */
/*   Updated: 2024/05/27 10:28:01 by mcygan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	error_handler(t_node **stack, char **argv, int allocated, int i)
{
	free_stacks(*stack, NULL);
	if (allocated)
		ft_free_split(argv, i);
	write(STDERR_FILENO, "Error\n", 6);
	return (exit(EXIT_FAILURE));
}

static void	node_init(t_node **stack, int value)
{
	t_node	*node;
	t_node	*last;

	node = malloc(sizeof(t_node));
	if (!node)
		return ;
	node->next = NULL;
	node->val = value;
	node->idx = -1;
	if (*stack)
	{
		last = get_tail(*stack);
		last->next = node;
		node->prev = last;
	}
	else
	{
		*stack = node;
		node->prev = NULL;
	}
}

static void	index_init(t_node *stack)
{
	int		idx;
	int		len;
	t_node	*min;
	t_node	*node;

	idx = 0;
	len = stack_size(stack);
	while (idx < len)
	{
		node = stack;
		while (node->idx > -1)
			node = node->next;
		min = node;
		while (node)
		{
			if (node->idx < 0 && node->val < min->val)
				min = node;
			node = node->next;
		}
		min->idx = idx++;
	}
}

static int	is_valid(const char *s, long nb, t_node *stack)
{
	while (*s && (*s == '+' || *s == '-'))
		s++;
	if (!*s)
		return (0);
	while (*s)
	{
		if (*s < '0' || *s > '9')
			return (0);
		s++;
	}
	if (nb < INT_MIN || nb > INT_MAX)
		return (0);
	while (stack)
	{
		if (stack->val == nb)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	stack_init(t_node **a, char **argv, int allocated)
{
	long	nb;
	int		i;

	if (!*argv)
	{
		if (allocated)
			return (error_handler(a, argv, 1, 0));
		else
			return (exit(EXIT_SUCCESS));
	}
	i = 0;
	while (argv[i])
	{
		nb = ft_atol(argv[i]);
		if (!is_valid(argv[i++], nb, *a))
			return (error_handler(a, argv, allocated, i));
		node_init(a, (int)nb);
	}
	if (allocated)
		ft_free_split(argv, i);
	index_init(*a);
}
