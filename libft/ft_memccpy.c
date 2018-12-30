/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrice <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 18:55:42 by hrice             #+#    #+#             */
/*   Updated: 2018/11/26 19:00:14 by hrice            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char *dst2;
	char *src2;

	dst2 = (char *)dst;
	src2 = (char *)src;
	while (n--)
	{
		if (*src2 == (char)(c % 256))
		{
			*dst2++ = *src2;
			return ((void *)dst2);
		}
		*dst2++ = *src2++;
	}
	if (dst2 == src2)
		return ((void *)dst2);
	return (NULL);
}
