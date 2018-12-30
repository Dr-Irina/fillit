/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrice <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 19:00:29 by hrice             #+#    #+#             */
/*   Updated: 2018/11/26 20:12:10 by hrice            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char *dst2;
	char *src2;

	if (dst == src)
		return (dst);
	dst2 = (char *)dst;
	src2 = (char *)src;
	while (n--)
		*dst2++ = *src2++;
	return (dst);
}
