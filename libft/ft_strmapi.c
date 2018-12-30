/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrice <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 16:31:51 by hrice             #+#    #+#             */
/*   Updated: 2018/11/28 18:02:49 by hrice            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*fresh;
	char			*fr;
	unsigned int	i;

	i = 0;
	if (!s || !f)
		return (NULL);
	fresh = ft_strnew(ft_strlen(s));
	if (!fresh)
		return (NULL);
	fr = fresh;
	while (*s)
	{
		*fresh = f(i, *s);
		fresh++;
		s++;
		i++;
	}
	return (fr);
}
