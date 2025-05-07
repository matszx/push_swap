/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcygan <mcygan@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 12:09:58 by mcygan            #+#    #+#             */
/*   Updated: 2024/05/30 11:49:38 by mcygan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4
# endif

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

// utils
long	ft_atol(const char *s);
int		stack_size(t_node *stack);
int		is_sorted(t_node *stack);
t_node	*get_tail(t_node *stack);
void	free_stacks(t_node *a, t_node *b);
void	*ft_free_split(char **strs, unsigned int n);
char	**ft_split(char const *s, char c);

// gnl
char	*get_next_line(int fd);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);

// operations
void	push(t_node **dst, t_node **src);
void	swap(t_node **stack);
void	rotate(t_node **stack);
void	rrotate(t_node **stack);

#endif