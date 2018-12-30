/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrice <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 18:45:31 by hrice             #+#    #+#             */
/*   Updated: 2018/11/26 21:01:15 by hrice            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	unsigned char	byte;

	str = (unsigned char *)s;
	byte = (unsigned char)(c % 256);
	while (n--)
	{
		if (*str == byte)
			return ((void *)str);
		str++;
	}
	return (NULL);
}
