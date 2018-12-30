/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrice <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 18:05:49 by hrice             #+#    #+#             */
/*   Updated: 2018/12/03 17:42:32 by hrice            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t		ft_wordlen(char *s, int st, char c)
{
	size_t			count;

	count = 0;
	if (!s)
		return (0);
	while (s[st] && s[st] != c)
	{
		st++;
		count++;
	}
	return (count);
}

static int			ft_cw(char *s, char c)
{
	int				cw;
	int				count;
	char			*str;

	str = (char *)s;
	cw = 0;
	count = 0;
	while (str[count])
	{
		if (str[count] != c && (str[count + 1] == c || str[count + 1] == '\0'))
			cw++;
		count++;
	}
	return (cw);
}

char				**ft_strsplit(char const *s, char c)
{
	char			**arr;
	unsigned int	count;
	int				i;

	count = 0;
	if (!s || !(arr = (char**)ft_memalloc(sizeof(s) *\
					(ft_cw((char *)s, c) + 1))))
		return (NULL);
	i = 0;
	while (i < ft_cw((char *)s, c))
	{
		while (s[count] && s[count] == c)
			count++;
		if (!(arr[i] = ft_strsub(s, count, ft_wordlen((char *)s, count, c))))
		{
			while (i--)
				free(arr[i]);
			free(arr);
		}
		while (s[count] && s[count] != c)
			count++;
		i++;
	}
	arr[i] = 0;
	return (arr);
}
