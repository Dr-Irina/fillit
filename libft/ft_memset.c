/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrice <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 19:09:21 by hrice             #+#    #+#             */
/*   Updated: 2018/11/26 19:35:04 by hrice            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t len)
{
	char	byte;
	size_t	i;
	char	*temp;

	temp = (char *)s;
	byte = (char)(c % 256);
	i = 0;
	while (i < len)
		temp[i++] = byte;
	return (s);
}
