/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcygan <mcygan@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 15:53:25 by mcygan            #+#    #+#             */
/*   Updated: 2024/05/27 09:28:55 by mcygan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap_bonus.h"

static int	ft_strcmp(const char *s1, const char *s2)
{
	if (!s1 || !s2)
		return (0);
	while (*s1 == *s2 && *s1)
	{
		s1++;
		s2++;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

static void	we_love_norminette(t_node **a, t_node **b, int flag)
{
	if (flag < 0)
	{
		swap(a);
		swap(b);
	}
	else if (flag == 0)
	{
		rotate(a);
		rotate(b);
	}
	else if (flag > 0)
	{
		rrotate(a);
		rrotate(b);
	}
}

static int	execute(char *line, t_node **a, t_node **b)
{
	if (!ft_strcmp(line, "pa\n"))
		push(a, b);
	else if (!ft_strcmp(line, "pb\n"))
		push(b, a);
	else if (!ft_strcmp(line, "sa\n"))
		swap(a);
	else if (!ft_strcmp(line, "sb\n"))
		swap(b);
	else if (!ft_strcmp(line, "ss\n"))
		we_love_norminette(a, b, -1);
	else if (!ft_strcmp(line, "ra\n"))
		rotate(a);
	else if (!ft_strcmp(line, "rb\n"))
		rotate(b);
	else if (!ft_strcmp(line, "rr\n"))
		we_love_norminette(a, b, 0);
	else if (!ft_strcmp(line, "rra\n"))
		rrotate(a);
	else if (!ft_strcmp(line, "rrb\n"))
		rrotate(b);
	else if (!ft_strcmp(line, "rrr\n"))
		we_love_norminette(a, b, 1);
	else
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_node	*a;
	t_node	*b;
	char	*line;

	if (argc == 2)
		stack_init(&a, ft_split(argv[1], 32), 1);
	else
		stack_init(&a, ++argv, 0);
	line = get_next_line(STDIN_FILENO);
	while (line)
	{
		if (execute(line, &a, &b))
		{
			free(line);
			free_stacks(a, b);
			return (write(STDERR_FILENO, "Error\n", 6), EXIT_FAILURE);
		}
		free(line);
		line = get_next_line(STDIN_FILENO);
	}
	if (!b && is_sorted(a))
		write(STDOUT_FILENO, "OK\n", 3);
	else
		write(STDOUT_FILENO, "KO\n", 3);
	return (free_stacks(a, b), EXIT_SUCCESS);
}
