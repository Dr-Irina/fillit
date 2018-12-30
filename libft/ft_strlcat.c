/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrice <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 16:38:08 by hrice             #+#    #+#             */
/*   Updated: 2018/11/30 14:42:56 by hrice            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	res;

	i = 0;
	res = ft_strlen(src);
	while (dst[i] && i < size)
		i++;
	j = 0;
	if (size > 0)
	{
		while (src[j] != '\0' && i < size - 1)
			dst[i++] = src[j++];
	}
	if (j > 0)
	{
		dst[i] = '\0';
		return (res + i - j);
	}
	return (res + i);
}
