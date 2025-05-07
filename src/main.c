/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcygan <mcygan@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 12:09:55 by mcygan            #+#    #+#             */
/*   Updated: 2024/04/22 17:44:28 by mcygan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	main(int argc, char **argv)
{
	t_node	*a;
	t_node	*b;

	if (argc == 2)
		stack_init(&a, ft_split(argv[1], 32), 1);
	else
		stack_init(&a, ++argv, 0);
	sort(&a, &b, stack_size(a));
	free_stacks(a, b);
	return (EXIT_SUCCESS);
}
