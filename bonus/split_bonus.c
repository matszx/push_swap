/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcygan <mcygan@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 10:36:39 by mcygan            #+#    #+#             */
/*   Updated: 2024/05/27 09:29:17 by mcygan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap_bonus.h"

void	*ft_free_split(char **strs, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n)
		free(strs[i++]);
	free(strs);
	return (NULL);
}

static unsigned int	ft_wc(char *str, char c)
{
	unsigned int	i;
	unsigned int	wc;

	i = 0;
	while (str[i])
		i++;
	wc = 0;
	while (i > 0)
	{
		if (str[i - 1] != c && (str[i] == c || !str[i]))
			wc++;
		i--;
	}
	return (wc);
}

static char	*ft_substr(char *str, char c)
{
	size_t			len;
	char			*res;
	unsigned int	i;

	len = 0;
	while (str[len] != c && str[len])
		len++;
	res = malloc(len + 1);
	if (!res)
		return (NULL);
	i = -1;
	while (++i < len)
		res[i] = str[i];
	res[i] = '\0';
	return (res);
}

char	**ft_split(char const *s, char c)
{
	unsigned int	wc;
	char			**res;
	unsigned int	i;

	wc = ft_wc((char *)s, c);
	res = malloc((wc + 1) * sizeof(char *));
	if (!res)
		return (NULL);
	i = 0;
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s)
		{
			res[i++] = ft_substr((char *)s, c);
			if (!res[i - 1])
				return (ft_free_split(res, i));
		}
		while (*s != c && *s)
			s++;
	}
	res[i] = 0;
	return (res);
}
