/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrice <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 18:51:21 by hrice             #+#    #+#             */
/*   Updated: 2018/11/26 21:03:25 by hrice            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*src2;
	char	*dst2;
	size_t	i;

	if (dst == src)
		return (dst);
	dst2 = (char *)dst;
	src2 = (char *)src;
	i = -1;
	if (dst2 < src2)
		while (++i < len)
			dst2[i] = src2[i];
	else
		while (len--)
			dst2[len] = src2[len];
	return (dst);
}
