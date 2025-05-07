/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcygan <mcygan@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 12:09:58 by mcygan            #+#    #+#             */
/*   Updated: 2024/05/27 09:18:13 by mcygan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_node
{
	int				val;
	int				idx;
	int				pos;
	int				d_val;
	int				p_val;
	int				lis;
	int				cost;
	void			*func;
	int				opti;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

// core
void	stack_init(t_node **a, char **argv, int allocated);
void	longest_increasing_subsequence(t_node *stack);
void	sort(t_node **a, t_node **b, int n);
void	stackfish(t_node **a, t_node **b);

// stackfish_utils
int		ft_abs(int nb);
t_node	*find_next(t_node **a, int elem);
t_node	*find_val_to_insert(t_node **a, t_node **b);

// utils
char	**ft_split(char const *s, char c);
void	*ft_free_split(char **strs, unsigned int n);
long	ft_atol(const char *s);
int		stack_size(t_node *stack);
int		is_sorted(t_node *stack);
t_node	*get_tail(t_node *stack);
void	free_stacks(t_node *a, t_node *b);

// operations
void	pa(t_node **a, t_node **b);
void	pb(t_node **a, t_node **b);
void	sa(t_node **a);
void	sb(t_node **b);
void	ss(t_node **a, t_node **b);
void	ra(t_node **a);
void	rb(t_node **b);
void	rr(t_node **a, t_node **b);
void	rra(t_node **a);
void	rrb(t_node **b);
void	rrr(t_node **a, t_node **b);

#endif